#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual void showInfo() = 0;
    virtual Employee* clone() = 0;  
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    void showInfo() override {
        cout << "This is a Manager." << endl;
    }

    Employee* clone() override {
        return new Manager(*this);  
    }
};

class Engineer : public Employee {
public:
    void showInfo() override {
        cout << "This is an Engineer." << endl;
    }

    Employee* clone() override {
        return new Engineer(*this);  
    }
};

class EmployeeFactory {
public:
    virtual Employee* createEmployee() = 0;  
    virtual ~EmployeeFactory() {}
};

class ManagerFactory : public EmployeeFactory {
public:
    Employee* createEmployee() override {
        return new Manager();  
    }
};

class EngineerFactory : public EmployeeFactory {
public:
    Employee* createEmployee() override {
        return new Engineer();  
    }
};

void clientCode(EmployeeFactory* factory) {
    Employee* employee = factory->createEmployee();  
    employee->showInfo();  

    delete employee;  
}

int main() {
    cout << "Creating Full-time Employees:\n";

    ManagerFactory managerFactory;
    clientCode(&managerFactory);  

    EngineerFactory engineerFactory;
    clientCode(&engineerFactory);  

    return 0;
}
