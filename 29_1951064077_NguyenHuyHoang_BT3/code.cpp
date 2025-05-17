#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual string MakeSound() const {
        return "Âm thanh chung của động vật";
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    string MakeSound() const override {
        return "GAU GAU";
    }
};

class Cat : public Animal {
public:
    string MakeSound() const override {
        return "Meow";
    }
};

class AnimalFactory {
public:
    virtual Animal* FactoryMethod() const = 0;  
    virtual ~AnimalFactory() {}
    
    void SomeOperation() const {
        Animal* animal = FactoryMethod();
        cout << animal->MakeSound() << endl;
        delete animal;
    }
};

class DogFactory : public AnimalFactory {
public:
    Animal* FactoryMethod() const override {
        return new Dog();
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal* FactoryMethod() const override {
        return new Cat();
    }
};

int main() {
    AnimalFactory* dogFactory = new DogFactory();
    AnimalFactory* catFactory = new CatFactory();

    dogFactory->SomeOperation();  
    catFactory->SomeOperation(); 

    delete dogFactory;
    delete catFactory;

    return 0;
}
