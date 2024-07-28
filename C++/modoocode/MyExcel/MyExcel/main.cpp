#include <iostream>
#include <fstream>
#include "excel.h"

int main() {
	MyExcel::TxtTable table(5, 5);
	std::ofstream out("test.txt");

	table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table), 0, 0);
	table.reg_cell(new MyExcel::Cell("C++", 0, 1, &table), 0, 1);
	table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table), 1, 1);

	std::cout << std::endl << table;
	out << table;

	MyExcel::CSVTable csv_table(5, 5);
	std::ofstream csv_out("test.csv");

	csv_table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &csv_table), 0, 0);
	csv_table.reg_cell(new MyExcel::Cell("C++", 0, 1, &csv_table), 0, 1);
	csv_table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &csv_table), 1, 1);

	csv_out << csv_table;

	MyExcel::HtmlTable html_table(5, 5);
	std::ofstream html_out("test.html");

	html_table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &html_table), 0, 0);
	html_table.reg_cell(new MyExcel::Cell("C++", 0, 1, &html_table), 0, 1);
	html_table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &html_table), 1, 1);

	html_out << html_table;

	return 0;
}