#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual string CreateSound() const = 0; 
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    string CreateSound() const override {
        return "GAU GAU";
    }
};

class Cat : public Animal {
public:
    string CreateSound() const override {
        return "Meow";
    }
};

class AnimalFactory {
public:
    virtual Animal* FactoryMethod() const = 0;  
    virtual ~AnimalFactory() {}
    
    void SomeOperation() const {
        Animal* animal = FactoryMethod();
        cout << animal->CreateSound() << endl;
        delete animal;
    }
};

class DogAnimal : public AnimalFactory {
public:
    Animal* FactoryMethod() const override {
        return new Dog();
    }
};

class CatAnimal : public AnimalFactory {
public:
    Animal* FactoryMethod() const override {
        return new Cat();
    }
};

int main() {
    AnimalFactory* dogFactory = new DogAnimal();
    AnimalFactory* catFactory = new CatAnimal();

    dogFactory->SomeOperation();  
    catFactory->SomeOperation();  

    delete dogFactory; 
    delete catFactory;

    return 0;
}
