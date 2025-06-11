#include <iostream>
#include <memory>
using namespace std;


class Component;


class Mediator {
public:
    virtual void notify(Component* sender) = 0;
    virtual ~Mediator() = default;
};

class Component {
protected:
    Mediator* mediator;

public:
    Component(Mediator* m) : mediator(m) {}
    virtual ~Component() = default;
};

class Employee;
class Manager;
class HRDepartment;

class Employee : public Component {
public:
    Employee(Mediator* m) : Component(m) {}

    void work() {
        cout << "Employee is working.\n";
        mediator->notify(this);
    }

    void report() {
        cout << "Employee sends report to Manager.\n";
    }
};

class Manager : public Component {
public:
    Manager(Mediator* m) : Component(m) {}

    void assign() {
        cout << "Manager assigns tasks.\n";
        mediator->notify(this);
    }

    void review() {
        cout << "Manager reviews report.\n";
    }
};

class HRDepartment : public Component {
public:
    HRDepartment(Mediator* m) : Component(m) {}

    void recruit() {
        cout << "HR recruits new employee.\n";
        mediator->notify(this);
    }

    void updatePolicy() {
        cout << "HR updates company policies.\n";
    }
};

class SystemMediator : public Mediator {
private:
    unique_ptr<Employee> employee;
    unique_ptr<Manager> manager;
    unique_ptr<HRDepartment> hr;

public:
    SystemMediator(unique_ptr<Employee> e, unique_ptr<Manager> m, unique_ptr<HRDepartment> h)
        : employee(move(e)), manager(move(m)), hr(move(h)) {}

    void notify(Component* sender) override {
        if (sender == employee.get()) {
            reactOnEmployee();
        } else if (sender == manager.get()) {
            reactOnManager();
        } else if (sender == hr.get()) {
            reactOnHR();
        }
    }

    void reactOnEmployee() {
        manager->review();
    }

    void reactOnManager() {
        employee->report();
    }

    void reactOnHR() {
        cout << "System logs HR activity.\n";
    }
};

int main() {
    
    unique_ptr<Employee> e = make_unique<Employee>(nullptr);
    unique_ptr<Manager> m = make_unique<Manager>(nullptr);
    unique_ptr<HRDepartment> h = make_unique<HRDepartment>(nullptr);

    
    unique_ptr<SystemMediator> mediator = make_unique<SystemMediator>(move(e), move(m), move(h));

    
    e->mediator = mediator.get();
    m->mediator = mediator.get();
    h->mediator = mediator.get();

    
    e->work();
    m->assign();
    h->recruit();

    
    return 0;
}
