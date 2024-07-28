#include "excel.h"
#include <iostream>
#include <sstream>

namespace MyExcel {

      // Cell implementation
      Cell::Cell(std::string data, int x, int y, Table* table)
            : data(data), x(x), y(y), table(table) {}

      std::string Cell::stringify() { return data; }
      int Cell::to_numeric() { return 0; }

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
            if (!(row < max_row_size && col < max_col_size)) return;
            if (data_table[row][col]) {
                  delete data_table[row][col];
            }
            data_table[row][col] = c;
      }

      int Table::to_numeric(const std::string& s) {
            int col = s[0] - 'A';
            int row = std::stoi(s.substr(1)) - 1;

            if (row < max_row_size && col < max_col_size) {
                  if (data_table[row][col]) {
                        return data_table[row][col]->to_numeric();
                  }
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

            if (row < max_row_size && col < max_col_size) {
                  if (data_table[row][col]) {
                        return data_table[row][col]->stringify();
                  }
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

            delete[] col_max_wide;
            return total_table;
      }

      std::string TxtTable::repeat_char(int n, char c) {
            return std::string(n, c);
      }

      std::string TxtTable::col_num_to_str(int n) {
            std::string s = "";
            if (n < 26) {
                  s.push_back('A' + n);
            }
            else {
                  char first = 'A' + n / 26 - 1;
                  char second = 'A' + n % 26;
                  s.push_back(first);
                  s.push_back(second);
            }
            return s;
      }

      // CSVTable implementation
      CSVTable::CSVTable(int row, int col) : Table(row, col) {}

      std::string CSVTable::print_table() {
            std::string s;
            for (int i = 0; i < max_row_size; i++) {
                  for (int j = 0; j < max_col_size; j++) {
                        if (j >= 1) s += ",";
                        std::string temp;
                        if (data_table[i][j]) temp = data_table[i][j]->stringify();
                        for (char& c : temp) {
                              if (c == '"') {
                                    s += "\"\"";
                              }
                              else {
                                    s += c;
                              }
                        }
                        s = "\"" + s + "\"";
                  }
                  s += '\n';
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
                        if (data_table[i][j]) s += data_table[i][j]->stringify();
                        s += "</td>";
                  }
                  s += "</tr>";
            }
            s += "</table>";
            return s;
      }

}  // namespace MyExcel

std::ostream& operator<<(std::ostream& o, MyExcel::Table& table) {
      o << table.print_table();
      return o;
}