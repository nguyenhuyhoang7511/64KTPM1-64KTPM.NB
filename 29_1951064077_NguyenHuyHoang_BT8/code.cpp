#include <iostream>
using namespace std;

class Mediator {
public:
    virtual void notify(void* sender) = 0;
    virtual ~Mediator() = default;
};

class Car {
private:
    Mediator* m;

public:
    Car(Mediator* m) : m(m) {}

    int getMaxSpeed() {
        cout << "Car: Tốc độ tối đa." << endl;
        m->notify(this);
        return 200;
    }
};

class Bicycle {
private:
    Mediator* m;

public:
    Bicycle(Mediator* m) : m(m) {}

    int getMaxSpeed() {
        cout << "Bicycle: Tốc độ tối đa" << endl;
        m->notify(this);
        return 40;
    }
};

class MediatorVehicle : public Mediator {
private:
    Car* componentCar;
    Bicycle* componentBicycle;

public:
    void setComponentCar(Car* car) {
        componentCar = car;
    }

    void setComponentBicycle(Bicycle* bicycle) {
        componentBicycle = bicycle;
    }

    void notify(void* sender) override {
        if (sender == componentCar) {
            reactOnCar();
        } else if (sender == componentBicycle) {
            reactOnBicycle();
        }
    }

private:
    void reactOnCar() {
        cout << "Mediator: Car." << endl;
    }

    void reactOnBicycle() {
        cout << "Mediator: Bicycle." << endl;
    }
};

int main() {
    MediatorVehicle mediator;

    Car car(&mediator);
    Bicycle bicycle(&mediator);

    mediator.setComponentCar(&car);
    mediator.setComponentBicycle(&bicycle);

    cout << "max speed car: " << car.getMaxSpeed() << " km/h" << endl;
    cout << "max speed bicycle: " << bicycle.getMaxSpeed() << " km/h" << endl;

    return 0;
}

