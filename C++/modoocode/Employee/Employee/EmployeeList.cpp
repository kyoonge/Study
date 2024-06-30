#include "Employee.h"

class EmployeeList {
	int alloc_employee;
	int current_employee;
	Employee** employee_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {
		// alloc_employee는 언제나 current_employee보다 크다
		employee_list[current_employee] = employee;
		current_employee++;
	}
	int current_employee_num() {
		return current_employee;
	}

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용: " << total_pay << "만원 " << std::endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};