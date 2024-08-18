#ifndef EXCEL_H
#define EXCEL_H

#include <string>
#include <ctime>
#include "utils.h"

namespace MyExcel {

	class Table;

	class Cell {
	protected:
		int x, y;
		Table* table;

	public:
		virtual std::string stringify() = 0;
		virtual int to_numeric() = 0;

		Cell(int x, int y, Table* table);
	};

	class StringCell : public Cell {
		std::string data;

	public:
		std::string stringify() override;
		int to_numeric() override;

		StringCell(std::string data, int x, int y, Table* t);
	};

	class NumberCell : public Cell {
		int data;

	public:
		std::string stringify() override;
		int to_numeric() override;

		NumberCell(int data, int x, int y, Table* t);
	};

	class DateCell : public Cell {
		time_t data;

	public:
		std::string stringify() override;
		int to_numeric() override;

		DateCell(std::string s, int x, int y, Table* t);
	};

	class ExprCell : public Cell {
		std::string data;
		Vector exp_vec;

		int precedence(char c);
		void parse_expression();

	public:
		ExprCell(std::string data, int x, int y, Table* t);

		std::string stringify() override;
		int to_numeric() override;
	};

	class Table {
	protected:
		int max_row_size, max_col_size;
		Cell*** data_table;

	public:
		Table(int max_row_size, int max_col_size);
		~Table();

		void reg_cell(Cell* c, int row, int col);
		int to_numeric(const std::string& s);
		int to_numeric(int row, int col);
		std::string stringify(const std::string& s);
		std::string stringify(int row, int col);
		virtual std::string print_table() = 0;
	};

	class TxtTable : public Table {
		std::string repeat_char(int n, char c);
		std::string col_num_to_str(int n);

	public:
		TxtTable(int row, int col);
		std::string print_table() override;
	};

	class CSVTable : public Table {
	public:
		CSVTable(int row, int col);
		std::string print_table() override;
	};

	class HtmlTable : public Table {
	public:
		HtmlTable(int row, int col);
		std::string print_table() override;
	};

	class Excel {
		Table* current_table;

	public:
		Excel(int max_row, int max_col, int choice);

		int parse_user_input(std::string s);
		void command_line();
	};

}  // namespace MyExcel

std::ostream& operator<<(std::ostream& o, MyExcel::Table& table);

#endif