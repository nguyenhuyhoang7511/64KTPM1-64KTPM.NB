#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class IEmployeeDisplay {
public:
    virtual void showEmployee() const = 0;
    virtual ~IEmployeeDisplay() {}
};

// Composite Class
class EmployeeGroup : public IEmployeeDisplay {
private:
    vector<IEmployeeDisplay*> employees; 

public:
    void addEmployee(IEmployeeDisplay* employee) {
        employees.push_back(employee);
    }

    void showEmployee() const override {
        for (auto& employee : employees) {
            employee->showEmployee(); 
        }
    }

    ~EmployeeGroup() {
        for (auto& employee : employees) {
            delete employee;
        }
    }
};

// Leaf Class - Hiển thị thông tin từng nhân viên
class Employee : public IEmployeeDisplay {
private:
    string name;
    int id;

public:
    Employee(const string& n, int i) : name(n), id(i) {}

    void showEmployee() const override {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }
};

class NewHRService {
public:
    void displayEmployeeInfo(const string& fullName, int id) {
        cout << "Employee Info:\n";
        cout << "Name: " << fullName << ", ID: " << id << endl;
    }
};

class HRAdapter : public IEmployeeDisplay {
private:
    NewHRService* service;
    unordered_map<string, int> nameToId; 

public:
    HRAdapter(NewHRService* svc) : service(svc) {
        nameToId["Nguyen Van A"] = 101;
        nameToId["Tran Thi B"] = 102;
    }

    void showEmployee() const override {
        for (const auto& entry : nameToId) {
            service->displayEmployeeInfo(entry.first, entry.second); 
        }
    }
};

int main() {
    
    NewHRService* newService = new NewHRService();
    HRAdapter* adapter = new HRAdapter(newService);

    
    EmployeeGroup* group = new EmployeeGroup();
    group->addEmployee(new Employee("Nguyen Van A", 101));
    group->addEmployee(new Employee("Tran Thi B", 102));
    group->addEmployee(adapter);  

    cout << "Displaying All Employees:\n";
    group->showEmployee();  

    delete group;  
    delete newService;  
    delete adapter;  

    return 0;
}
