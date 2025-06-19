#include <iostream>
#include <string>
using namespace std;


class IAnimal {
public:
    virtual double Speed() const = 0;      
    virtual string Info() const = 0;       
    virtual string getColor() const = 0;   
    virtual ~IAnimal() = default;          
};


class Dog : public IAnimal {
public:
    double Speed() const override {
        return 30.0;  
    }

    string Info() const override {
        return "Golden Retriever Dog";  
    }

    string getColor() const override {
        return "Golden";  
    }
};


class Cat : public IAnimal {
public:
    double Speed() const override {
        return 20.0;  
    }

    string Info() const override {
        return "Persian Cat";  
    }

    string getColor() const override {
        return "White";  
    }
};


class AnimalAbstraction {
protected:
    IAnimal* animal;

public:
    AnimalAbstraction(IAnimal* animal) : animal(animal) {}

    virtual double getSpeed() const {
        return animal->Speed();
    }

    virtual string getInfo() const {
        return animal->Info();
    }

    string getColor() const {
        return animal->getColor();
    }
};


class AdvancedAnimal : public AnimalAbstraction {
private:
    string premiumColor;

public:
    AdvancedAnimal(IAnimal* animal) : AnimalAbstraction(animal), premiumColor("Shiny") {}

    double getSpeed() const override {
        return animal->Speed() * 1.5;  
    }

    string getInfo() const override {
        return animal->Info() + " (Premium)";  
    }

    string getPremiumColor() const {
        return premiumColor + " " + animal->getColor();  
    }
};


void printAnimalInfo(const AnimalAbstraction& animal) {
    cout << "Animal: " << animal.getInfo() << endl;
    cout << "Speed: " << animal.getSpeed() << " km/h" << endl;
    cout << "Color: " << animal.getColor() << endl;
}

int main() {
    IAnimal* dog = new Dog();
    IAnimal* cat = new Cat();

    
    cout << "Basic Animals" << endl;
    AnimalAbstraction basicDog(dog);
    AnimalAbstraction basicCat(cat);

    printAnimalInfo(basicDog);
    printAnimalInfo(basicCat);

    cout << "\nAdvanced Animals" << endl;
    AdvancedAnimal premiumDog(dog);
    AdvancedAnimal premiumCat(cat);

    printAnimalInfo(premiumDog);
    printAnimalInfo(premiumCat);
    cout << "Premium Dog Color: " << premiumDog.getPremiumColor() << endl;
    cout << "Premium Cat Color: " << premiumCat.getPremiumColor() << endl;

    delete dog;
    delete cat;

    return 0;
}
