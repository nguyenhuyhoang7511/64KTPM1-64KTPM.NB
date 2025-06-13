#include <iostream>
#include <string>
using namespace std;

class SpeedStrategy {
public:
    virtual int getMaxSpeed() const = 0;
    virtual string getColor() const = 0;
    virtual ~SpeedStrategy() = default;
};

class CarStrategy : public SpeedStrategy {
private:
    string color;

public:
    CarStrategy(const string& color) : color(color) {}

    int getMaxSpeed() const override {
        return 200;
    }

    string getColor() const override {
        return color;
    }
};

class BicycleStrategy : public SpeedStrategy {
private:
    string color;

public:
    BicycleStrategy(const string& color) : color(color) {}

    int getMaxSpeed() const override {
        return 40;
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

    string getVehicleColor() const {
        if (strategy != nullptr) {
            return strategy->getColor();
        }
        return "Unknown";
    }
};

int main() {
    Context context;

    SpeedStrategy* car = new CarStrategy("Red");
    context.setStrategy(car);
    cout << "car max speed : " << context.getMaxSpeed() << endl;
    cout << "car color: " << context.getVehicleColor() << endl;

    SpeedStrategy* bicycle = new BicycleStrategy("Xanh");
    context.setStrategy(bicycle);
    cout << "vehicle max speed: " << context.getMaxSpeed() << endl;
    cout << "vehicle max speed: " << context.getVehicleColor() << endl;

    delete car;
    delete bicycle;

    return 0;
}
