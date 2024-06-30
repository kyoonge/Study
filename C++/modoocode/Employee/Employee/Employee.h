#include <iostream>
#include <string>
#pragma once

class Employee {
protected:
	std::string name;
	int age;

	std::string position;	//��å
	int rank;		//����

public:
	Employee(std::string name, int age, std::string position, int rank);
	Employee(const Employee& employee);
	//����Ʈ ������
	Employee();
	void print_info();
	int calculate_pay();
};