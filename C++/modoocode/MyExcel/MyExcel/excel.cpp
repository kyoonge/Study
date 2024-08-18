#include "excel.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

namespace MyExcel {

      // Cell implementation
      Cell::Cell(int x, int y, Table* table) : x(x), y(y), table(table) {}

      // StringCell implementation
      StringCell::StringCell(std::string data, int x, int y, Table* t)
            : Cell(x, y, t), data(data) {}

      std::string StringCell::stringify() { return data; }
      int StringCell::to_numeric() { return 0; }

      // NumberCell implementation
      NumberCell::NumberCell(int data, int x, int y, Table* t)
            : Cell(x, y, t), data(data) {}

      std::string NumberCell::stringify() { return std::to_string(data); }
      int NumberCell::to_numeric() { return data; }

      // DateCell implementation
      DateCell::DateCell(std::string s, int x, int y, Table* t) : Cell(x, y, t) {
            int year = std::stoi(s.substr(0, 4));
            int month = std::stoi(s.substr(5, 2));
            int day = std::stoi(s.substr(8, 2));

            struct tm timeinfo = {};
            timeinfo.tm_year = year - 1900;
            timeinfo.tm_mon = month - 1;
            timeinfo.tm_mday = day;
            data = mktime(&timeinfo);
      }

      std::string DateCell::stringify() {
            char buf[11];
            struct tm timeinfo;
            localtime_s(&timeinfo, &data);
            strftime(buf, sizeof(buf), "%Y-%m-%d", &timeinfo);
            return std::string(buf);
      }

      int DateCell::to_numeric() { return static_cast<int>(data); }

      // ExprCell implementation
      ExprCell::ExprCell(std::string data, int x, int y, Table* t)
            : Cell(x, y, t), data(data) {
            parse_expression();
      }

      int ExprCell::precedence(char c) {
            switch (c) {
            case '(':
            case '[':
            case '{':
                  return 0;
            case '+':
            case '-':
                  return 1;
            case '*':
            case '/':
                  return 2;
            }
            return 0;
      }

      void ExprCell::parse_expression() {
            Stack stack;
            data.insert(0, "(");
            data.push_back(')');

            for (size_t i = 0; i < data.length(); i++) {
                  if (isalpha(data[i])) {
                        exp_vec.push_back(data.substr(i, 2));
                        i++;
                  }
                  else if (isdigit(data[i])) {
                        exp_vec.push_back(data.substr(i, 1));
                  }
                  else if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
                        stack.push(data.substr(i, 1));
                  }
                  else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
                        std::string t = stack.pop();
                        while (t != "(" && t != "[" && t != "{") {
                              exp_vec.push_back(t);
                              t = stack.pop();
                        }
                  }
                  else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/') {
                        while (!stack.is_empty() && precedence(stack.peek()[0]) >= precedence(data[i])) {
                              exp_vec.push_back(stack.pop());
                        }
                        stack.push(data.substr(i, 1));
                  }
            }
      }

      std::string ExprCell::stringify() { return data; }

      int ExprCell::to_numeric() {
            NumStack stack;
            for (int i = 0; i < exp_vec.size(); i++) {
                  std::string s = exp_vec[i];
                  if (isalpha(s[0])) {
                        stack.push(table->to_numeric(s));
                  }
                  else if (isdigit(s[0])) {
                        stack.push(std::stoi(s));
                  }
                  else {
                        double y = stack.pop();
                        double x = stack.pop();
                        switch (s[0]) {
                        case '+': stack.push(x + y); break;
                        case '-': stack.push(x - y); break;
                        case '*': stack.push(x * y); break;
                        case '/': stack.push(x / y); break;
                        }
                  }
            }
            return stack.pop();
      }

      // Table implementation
      Table::Table(int max_row_size, int max_col_size)
            : max_row_size(max_row_size), max_col_size(max_col_size) {
            data_table = new Cell * *[max_row_size];
            for (int i = 0; i < max_row_size; i++) {
                  data_table[i] = new Cell * [max_col_size];
                  for (int j = 0; j < max_col_size; j++) {
                        data_table[i][j] = nullptr;
                  }
            }
      }

      Table::~Table() {
            for (int i = 0; i < max_row_size; i++) {
                  for (int j = 0; j < max_col_size; j++) {
                        if (data_table[i][j]) delete data_table[i][j];
                  }
                  delete[] data_table[i];
            }
            delete[] data_table;
      }

      void Table::reg_cell(Cell* c, int row, int col) {
            if (row < max_row_size && col < max_col_size) {
                  if (data_table[row][col]) delete data_table[row][col];
                  data_table[row][col] = c;
            }
      }

      int Table::to_numeric(const std::string& s) {
            int col = s[0] - 'A';
            int row = std::stoi(s.substr(1)) - 1;

            if (row < max_row_size && col < max_col_size && data_table[row][col]) {
                  return data_table[row][col]->to_numeric();
            }
            return 0;
      }

      int Table::to_numeric(int row, int col) {
            if (row < max_row_size && col < max_col_size && data_table[row][col]) {
                  return data_table[row][col]->to_numeric();
            }
            return 0;
      }

      std::string Table::stringify(const std::string& s) {
            int col = s[0] - 'A';
            int row = std::stoi(s.substr(1)) - 1;

            if (row < max_row_size && col < max_col_size && data_table[row][col]) {
                  return data_table[row][col]->stringify();
            }
            return "";
      }

      std::string Table::stringify(int row, int col) {
            if (row < max_row_size && col < max_col_size && data_table[row][col]) {
                  return data_table[row][col]->stringify();
            }
            return "";
      }

      // TxtTable implementation
      TxtTable::TxtTable(int row, int col) : Table(row, col) {}

      std::string TxtTable::repeat_char(int n, char c) {
            return std::string(n, c);
      }

      std::string TxtTable::col_num_to_str(int n) {
            std::string s = "";
            if (n < 26) {
                  s += static_cast<char>('A' + n);
            }
            else {
                  s += static_cast<char>('A' + (n / 26) - 1);
                  s += static_cast<char>('A' + (n % 26));
            }
            return s;
      }

      std::string TxtTable::print_table() {
            std::string total_table;

            int* col_max_wide = new int[max_col_size];
            for (int i = 0; i < max_col_size; i++) {
                  unsigned int max_wide = 2;
                  for (int j = 0; j < max_row_size; j++) {
                        if (data_table[j][i] &&
                              data_table[j][i]->stringify().length() > max_wide) {
                              max_wide = data_table[j][i]->stringify().length();
                        }
                  }
                  col_max_wide[i] = max_wide;
            }
            // 맨 상단에 열 정보 표시
            total_table += "    ";
            int total_wide = 4;
            for (int i = 0; i < max_col_size; i++) {
                  if (col_max_wide[i]) {
                        int max_len = std::max(2, col_max_wide[i]);
                        total_table += " | " + col_num_to_str(i);
                        total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

                        total_wide += (max_len + 3);
                  }
            }

            total_table += "\n";
            // 일단 기본적으로 최대 9999 번째 행 까지 지원한다고 생각한다.
            for (int i = 0; i < max_row_size; i++) {
                  total_table += repeat_char(total_wide, '-');
                  total_table += "\n" + std::to_string(i + 1);
                  total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');

                  for (int j = 0; j < max_col_size; j++) {
                        if (col_max_wide[j]) {
                              int max_len = std::max(2, col_max_wide[j]);

                              std::string s = "";
                              if (data_table[i][j]) {
                                    s = data_table[i][j]->stringify();
                              }
                              total_table += " | " + s;
                              total_table += repeat_char(max_len - s.length(), ' ');
                        }
                  }
                  total_table += "\n";
            }

            return total_table;
      }

      // CSVTable implementation
      CSVTable::CSVTable(int row, int col) : Table(row, col) {}

      std::string CSVTable::print_table() {
            std::string s;
            for (int i = 0; i < max_row_size; i++) {
                  for (int j = 0; j < max_col_size; j++) {
                        if (j > 0) s += ",";
                        if (data_table[i][j]) {
                              std::string cell_data = data_table[i][j]->stringify();
                              if (cell_data.find('"') != std::string::npos) {
                                    // Escape double quotes
                                    size_t pos = 0;
                                    while ((pos = cell_data.find('"', pos)) != std::string::npos) {
                                          cell_data.replace(pos, 1, "\"\"");
                                          pos += 2;
                                    }
                              }
                              s += "\"" + cell_data + "\"";
                        }
                  }
                  s += "\n";
            }
            return s;
      }

      // HtmlTable implementation
      HtmlTable::HtmlTable(int row, int col) : Table(row, col) {}

      std::string HtmlTable::print_table() {
            std::string s = "<table border='1' cellpadding='10'>";
            for (int i = 0; i < max_row_size; i++) {
                  s += "<tr>";
                  for (int j = 0; j < max_col_size; j++) {
                        s += "<td>";
                        if (data_table[i][j]) {
                              s += data_table[i][j]->stringify();
                        }
                        s += "</td>";
                  }
                  s += "</tr>";
            }
            s += "</table>";
            return s;
      }

      // Excel implementation
      Excel::Excel(int max_row, int max_col, int choice) {
            switch (choice) {
            case 0:
                  current_table = new TxtTable(max_row, max_col);
                  break;
            case 1:
                  current_table = new CSVTable(max_row, max_col);
                  break;
            default:
                  current_table = new HtmlTable(max_row, max_col);
            }
      }

      int Excel::parse_user_input(std::string s) {
            std::istringstream iss(s);
            std::string command, to, rest;
            iss >> command >> to;
            std::getline(iss, rest);
            rest = rest.substr(rest.find_first_not_of(" \t"));

            int col = to[0] - 'A';
            int row = std::stoi(to.substr(1)) - 1;

            if (command == "sets") {
                  current_table->reg_cell(new StringCell(rest, row, col, current_table), row, col);
            }
            else if (command == "setn") {
                  current_table->reg_cell(new NumberCell(std::stoi(rest), row, col, current_table), row, col);
            }
            else if (command == "setd") {
                  current_table->reg_cell(new DateCell(rest, row, col, current_table), row, col);
            }
            else if (command == "sete") {
                  current_table->reg_cell(new ExprCell(rest, row, col, current_table), row, col);
            }
            else if (command == "out") {
                  std::ofstream out(to);
                  out << *current_table;
                  std::cout << to << " 에 내용이 저장되었습니다" << std::endl;
            }
            else if (command == "exit") {
                  return 0;
            }

            return 1;
      }

      void Excel::command_line() {
            std::string s;
            if (current_table) {
                  std::cout << *current_table << std::endl;
            }
            else {
                  std::cout << "테이블이 초기화되지 않았습니다." << std::endl;
            }
            std::cout << ">> ";
            std::getline(std::cin, s);
            while (parse_user_input(s)) {
                  if (current_table) {
                        std::cout << *current_table << std::endl;
                  }
                  std::cout << ">> ";
                  std::getline(std::cin, s);
            }
      }

}  // namespace MyExcel

std::ostream& operator<<(std::ostream& o, MyExcel::Table& table) {
      o << table.print_table();
      return o;
}