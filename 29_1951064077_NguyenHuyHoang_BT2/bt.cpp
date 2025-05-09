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

int main() {
    Animal* animals[2];
    animals[0] = new Dog();  
    animals[1] = new Cat();  

    for (int i = 0; i < 2; ++i) {
        cout << animals[i]->MakeSound() << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}
