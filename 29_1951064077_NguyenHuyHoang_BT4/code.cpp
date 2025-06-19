#include <iostream>
#include <memory>
using namespace std;

// 
class IAnimal {
public:
    virtual void makeSound() const = 0;  
    virtual ~IAnimal() = default;         
};


class Dog : public IAnimal {
public:
    void makeSound() const override {
        cout << "Dog: Woof!" << endl;
    }
};


class Cat : public IAnimal {
public:
    void makeSound() const override {
        cout << "Cat: Meow!" << endl;
    }
};


class AnimalFactory {
public:
    virtual unique_ptr<IAnimal> createAnimal() const = 0;  
    virtual ~AnimalFactory() = default;                    
};


class DogFactory : public AnimalFactory {
public:
    unique_ptr<IAnimal> createAnimal() const override {
        return make_unique<Dog>();  
    }
};


class CatFactory : public AnimalFactory {
public:
    unique_ptr<IAnimal> createAnimal() const override {
        return make_unique<Cat>();  
    }
};


class Client {
private:
    unique_ptr<AnimalFactory> factory;  

public:
    Client(unique_ptr<AnimalFactory> factory) : factory(move(factory)) {}

    void someOperation() const {
        auto animal = factory->createAnimal();  
        animal->makeSound();  
    }
};

int main() {
    cout << "== Dog Factory ==" << endl;
    Client clientDog(make_unique<DogFactory>());
    clientDog.someOperation();  

    cout << "\n== Cat Factory ==" << endl;
    Client clientCat(make_unique<CatFactory>());
    clientCat.someOperation();  

    return 0;
}
