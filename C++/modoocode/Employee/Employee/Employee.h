#include <iostream>
#include <string>
#pragma once

class Employee {
protected:
	std::string name;
	int age;

	std::string position;	//직책
	int rank;		//순위

public:
	Employee(std::string name, int age, std::string position, int rank);
	Employee(const Employee& employee);
	//디폴트 생성자
	Employee();
	void print_info();
	int calculate_pay();
};