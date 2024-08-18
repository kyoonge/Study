#include <iostream>
#include <string>
#include "excel.h"

int main() {
	std::cout << "���̺� (Ÿ��) (�ִ� �� ũ��) (�ִ� �� ũ��) �� ������� �Է����ּ���" << std::endl;
	std::cout << "* ���� * " << std::endl;
	std::cout << "1 : �ؽ�Ʈ ���̺�, 2 : CSV ���̺�, 3 : HTML ���̺�" << std::endl;

	int type, max_row, max_col;
	std::cin >> type >> max_row >> max_col;
	std::cin.ignore(); // ���� ����

	MyExcel::Excel excel(max_row, max_col, type - 1);

	std::cout << "Excel ���α׷��� ���۵Ǿ����ϴ�. ��ɾ �Է��ϼ���." << std::endl;
	std::cout << "��� ������ ��ɾ�:" << std::endl;
	std::cout << "  sets <��> <���ڿ�>  : ���ڿ� �� ����" << std::endl;
	std::cout << "  setn <��> <����>    : ���� �� ����" << std::endl;
	std::cout << "  setd <��> <��¥>    : ��¥ �� ���� (YYYY-MM-DD ����)" << std::endl;
	std::cout << "  sete <��> <����>    : ���� �� ����" << std::endl;
	std::cout << "  out <���ϸ�>        : ���� ���̺��� ���Ϸ� ����" << std::endl;
	std::cout << "  exit                : ���α׷� ����" << std::endl;

	excel.command_line();

	return 0;
}