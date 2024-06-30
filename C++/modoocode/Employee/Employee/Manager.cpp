#include "Employee.h"

class Manager : public Employee {
      int year_of_service;

public:
      Manager(std::string name, int age, std::string position, int rank,
            int year_of_service)
            : year_of_service(year_of_service), Employee(name, age, position, rank) {}

      // 복사 생성자
      Manager(const Manager& manager)
            : Employee(manager.name, manager.age, manager.position, manager.rank) {
            year_of_service = manager.year_of_service;
      }

      // 디폴트 생성자
      Manager() : Employee() {}

      int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
      void print_info() {
            std::cout << name << " (" << position << " , " << age << ", "
                  << year_of_service << "년차) ==> " << calculate_pay() << "만원"
                  << std::endl;
      }
};