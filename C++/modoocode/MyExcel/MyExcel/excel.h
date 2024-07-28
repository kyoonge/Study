#pragma once
#ifndef EXCEL_H
#define EXCEL_H

#include <string>
#include "utils.h"

namespace MyExcel {

	class Table;

	class Cell {
	protected:
		int x, y;
		Table* table;
		std::string data;

	public:
		virtual std::string stringify();
		virtual int to_numeric();
		Cell(std::string data, int x, int y, Table* table);
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

}  // namespace MyExcel

std::ostream& operator<<(std::ostream& o, MyExcel::Table& table);

#endif