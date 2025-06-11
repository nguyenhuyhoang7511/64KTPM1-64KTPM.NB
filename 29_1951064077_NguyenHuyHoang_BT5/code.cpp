#include <iostream>
#include <string>
#include <memory>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;

public:
    Employee& setName(const std::string& n) {
        name = n;
        return *this;
    }

    Employee& setPosition(const std::string& p) {
        position = p;
        return *this;
    }

    Employee& setSalary(double s) {
        salary = s;
        return *this;
    }

    void showInfo() const {
        std::cout << "Name: " << name << "\n"
                  << "Position: " << position << "\n"
                  << "Salary: $" << salary << "\n";
    }
};

int main() {
    
    std::shared_ptr<Employee> dev = std::make_shared<Employee>();
    dev->setName("Nguyen Van A")
        .setPosition("Developer")
        .setSalary(1500.0);
    
    std::cout << "Developer Info:\n";
    dev->showInfo();

    std::cout << "\n";

    
    std::shared_ptr<Employee> mgr = std::make_shared<Employee>();
    mgr->setName("Tran Thi B")
        .setPosition("Manager")
        .setSalary(3000.0);

    std::cout << "Manager Info:\n";
    mgr->showInfo();

    return 0;
}
