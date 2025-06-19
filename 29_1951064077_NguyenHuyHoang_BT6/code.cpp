#include <iostream>
using namespace std;


class AnimalInterface {
public:
    virtual void makeSound() = 0;
    virtual void move() = 0;
    virtual ~AnimalInterface() = default;
};


class DogService {
public:
    void bark() {
        cout << "DogService: Woof Woof!!!" << endl;
    }

    void run() {
        cout << "DogService: Running fast!!!" << endl;
    }
};


class DogServiceAdapter : public AnimalInterface {
private:
    DogService* adaptee;

public:
    DogServiceAdapter(DogService* service) : adaptee(service) {}

    void makeSound() override {
        adaptee->bark();  
    }

    void move() override {
        adaptee->run();  
    }
};

int main() {
    DogService dogService;
    AnimalInterface* animal = new DogServiceAdapter(&dogService);

    animal->makeSound();  
    animal->move();       

    delete animal;  
    return 0;
}
