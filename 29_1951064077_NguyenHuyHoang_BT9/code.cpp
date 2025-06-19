#include <iostream>
#include <string>
using namespace std;


class SpeedStrategy {
public:
    virtual int getMaxSpeed() const = 0;
    virtual string getColor() const = 0;
    virtual ~SpeedStrategy() = default;
};


class DogStrategy : public SpeedStrategy {
private:
    string color;

public:
    DogStrategy(const string& color) : color(color) {}

    int getMaxSpeed() const override {
        return 30;  
    }

    string getColor() const override {
        return color;  
    }
};


class CatStrategy : public SpeedStrategy {
private:
    string color;

public:
    CatStrategy(const string& color) : color(color) {}

    int getMaxSpeed() const override {
        return 20;  
    }

    string getColor() const override {
        return color;  
    }
};


class Context {
private:
    SpeedStrategy* strategy;

public:
    void setStrategy(SpeedStrategy* strategy) {
        this->strategy = strategy;
    }

    int getMaxSpeed() const {
        if (strategy != nullptr) {
            return strategy->getMaxSpeed();
        }
        return 0;
    }

    string getAnimalColor() const {
        if (strategy != nullptr) {
            return strategy->getColor();
        }
        return "Unknown";
    }
};

int main() {
    Context context;

    
    SpeedStrategy* dog = new DogStrategy("Brown");
    context.setStrategy(dog);
    cout << "Dog max speed: " << context.getMaxSpeed() << " km/h" << endl;
    cout << "Dog color: " << context.getAnimalColor() << endl;

    
    SpeedStrategy* cat = new CatStrategy("White");
    context.setStrategy(cat);
    cout << "Cat max speed: " << context.getMaxSpeed() << " km/h" << endl;
    cout << "Cat color: " << context.getAnimalColor() << endl;

    delete dog;
    delete cat;

    return 0;
}
