#include <iostream>
#include <string>
#include <vector>
#include <memory>


class IObserver {
public:
    virtual void update(const std::string& event) = 0;
    virtual ~IObserver() = default;
};


class ISubject {
public:
    virtual void addObserver(std::shared_ptr<IObserver> observer) = 0;
    virtual void removeObserver(std::shared_ptr<IObserver> observer) = 0;
    virtual void notifyObservers(const std::string& event) = 0;
    virtual ~ISubject() = default;
};


class Employee : public IObserver {
public:
    void update(const std::string& event) override {
        if (event == "leaveRequest") {
            std::cout << "Employee: Leave request is under review.\n";
        } else if (event == "updateInfo") {
            std::cout << "Employee: Info updated successfully.\n";
        }
    }

    void requestLeave(ISubject* subject) {
        std::cout << "Employee: Requesting leave.\n";
        subject->notifyObservers("leaveRequest");
    }

    void updateInfo(ISubject* subject) {
        std::cout << "Employee: Updating info.\n";
        subject->notifyObservers("updateInfo");
    }
};


class Department : public IObserver {
public:
    void update(const std::string& event) override {
        if (event == "leaveRequest") {
            std::cout << "Department: Notifying about leave request.\n";
        } else if (event == "updateInfo") {
            std::cout << "Department: Info update processed.\n";
        }
    }

    void assignEmployee(ISubject* subject) {
        std::cout << "Department: Assigning employee.\n";
        subject->notifyObservers("assign");
    }
};


class Manager : public IObserver {
public:
    void update(const std::string& event) override {
        if (event == "leaveRequest") {
            std::cout << "Manager: Leave request approved.\n";
        } else if (event == "assign") {
            std::cout << "Manager: Employee assigned to a new task.\n";
        }
    }

    void reviewLeave(ISubject* subject) {
        std::cout << "Manager: Reviewing leave request.\n";
        subject->notifyObservers("leaveRequest");
    }
};


class ConcreteSubject : public ISubject {
private:
    std::vector<std::shared_ptr<IObserver>> observers;

public:
    void addObserver(std::shared_ptr<IObserver> observer) override {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<IObserver> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& event) override {
        for (const auto& observer : observers) {
            observer->update(event);
        }
    }
};

int main() {
    std::shared_ptr<ConcreteSubject> subject = std::make_shared<ConcreteSubject>();

    std::shared_ptr<Employee> emp = std::make_shared<Employee>();
    std::shared_ptr<Department> dept = std::make_shared<Department>();
    std::shared_ptr<Manager> mgr = std::make_shared<Manager>();

    subject->addObserver(emp);
    subject->addObserver(dept);
    subject->addObserver(mgr);

    emp->requestLeave(subject.get());
    emp->updateInfo(subject.get());
    dept->assignEmployee(subject.get());
    mgr->reviewLeave(subject.get());

    return 0;
}
