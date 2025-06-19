#include <iostream>
using namespace std;


class Mediator {
public:
    virtual void notify(void* sender) = 0;
    virtual ~Mediator() = default;
};


class Dog {
private:
    Mediator* m;

public:
    Dog(Mediator* m) : m(m) {}

    int getMaxSpeed() {
        cout << "Dog: Running speed." << endl;
        m->notify(this);
        return 30;  
    }
};


class Cat {
private:
    Mediator* m;

public:
    Cat(Mediator* m) : m(m) {}

    int getMaxSpeed() {
        cout << "Cat: Running speed." << endl;
        m->notify(this);
        return 20;  
    }
};


class MediatorAnimal : public Mediator {
private:
    Dog* componentDog;
    Cat* componentCat;

public:
    void setComponentDog(Dog* dog) {
        componentDog = dog;
    }

    void setComponentCat(Cat* cat) {
        componentCat = cat;
    }

    void notify(void* sender) override {
        if (sender == componentDog) {
            reactOnDog();
        } else if (sender == componentCat) {
            reactOnCat();
        }
    }

private:
    void reactOnDog() {
        cout << "Mediator: Dog is running." << endl;
    }

    void reactOnCat() {
        cout << "Mediator: Cat is running." << endl;
    }
};

int main() {
    
    MediatorAnimal mediator;

    
    Dog dog(&mediator);
    Cat cat(&mediator);

    
    mediator.setComponentDog(&dog);
    mediator.setComponentCat(&cat);

    
    cout << "Max speed of dog: " << dog.getMaxSpeed() << " km/h" << endl;
    cout << "Max speed of cat: " << cat.getMaxSpeed() << " km/h" << endl;

    return 0;
}
