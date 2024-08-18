#include <iostream>
#include <string>
#include "excel.h"

int main() {
	std::cout << "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요" << std::endl;
	std::cout << "* 참고 * " << std::endl;
	std::cout << "1 : 텍스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블" << std::endl;

	int type, max_row, max_col;
	std::cin >> type >> max_row >> max_col;
	std::cin.ignore(); // 버퍼 비우기

	MyExcel::Excel excel(max_row, max_col, type - 1);

	std::cout << "Excel 프로그램이 시작되었습니다. 명령어를 입력하세요." << std::endl;
	std::cout << "사용 가능한 명령어:" << std::endl;
	std::cout << "  sets <셀> <문자열>  : 문자열 셀 설정" << std::endl;
	std::cout << "  setn <셀> <숫자>    : 숫자 셀 설정" << std::endl;
	std::cout << "  setd <셀> <날짜>    : 날짜 셀 설정 (YYYY-MM-DD 형식)" << std::endl;
	std::cout << "  sete <셀> <수식>    : 수식 셀 설정" << std::endl;
	std::cout << "  out <파일명>        : 현재 테이블을 파일로 저장" << std::endl;
	std::cout << "  exit                : 프로그램 종료" << std::endl;

	excel.command_line();

	return 0;
}