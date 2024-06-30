#include "Employee.h"

Employee::Employee(std::string name, int age, std::string position, int rank)
    : name(name), age(age), position(position), rank(rank) {}

Employee::Employee(const Employee& employee) {
    name = employee.name;
    age = employee.age;
    position = employee.position;
    rank = employee.rank;
}

Employee::Employee() {}

void Employee::print_info() {
    std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "¸¸¿ø" << std::endl;
}

int Employee::calculate_pay() {
    return 200 + rank * 50;
}