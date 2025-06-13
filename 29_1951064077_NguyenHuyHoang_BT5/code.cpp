#include <iostream>
#include <memory>
using namespace std;

class VehicleBuilder {
public:
    virtual void reset() = 0;
    virtual void setMaxSpeed(int speed) = 0;
    virtual void setWheels(int number) = 0;
    virtual ~VehicleBuilder() = default;
};

class Car {
private:
    int maxSpeed;
    int wheels;

public:
    int getMaxSpeed() const { return maxSpeed; }
    int getWheels() const { return wheels; }

    void setMaxSpeed(int maxSpeed) { this->maxSpeed = maxSpeed; }
    void setWheels(int wheels) { this->wheels = wheels; }

    string toString() const {
        return "Car{maxSpeed=" + to_string(maxSpeed) + ", wheels=" + to_string(wheels) + "}";
    }
};

class Bicycle {
private:
    int maxSpeed;
    int wheels;

public:
    int getMaxSpeed() const { return maxSpeed; }
    int getWheels() const { return wheels; }

    void setMaxSpeed(int maxSpeed) { this->maxSpeed = maxSpeed; }
    void setWheels(int wheels) { this->wheels = wheels; }

    string toString() const {
        return "Bicycle{maxSpeed=" + to_string(maxSpeed) + ", wheels=" + to_string(wheels) + "}";
    }
};

class CarBuilder : public VehicleBuilder {
private:
    unique_ptr<Car> car;

public:
    CarBuilder() : car(make_unique<Car>()) {}

    void reset() override {
        car = make_unique<Car>();
    }

    void setMaxSpeed(int speed) override {
        car->setMaxSpeed(speed);
    }

    void setWheels(int number) override {
        car->setWheels(number);
    }

    Car getResult() {
        return *car;
    }
};

class BicycleBuilder : public VehicleBuilder {
private:
    unique_ptr<Bicycle> bicycle;

public:
    BicycleBuilder() : bicycle(make_unique<Bicycle>()) {}

    void reset() override {
        bicycle = make_unique<Bicycle>();
    }

    void setMaxSpeed(int speed) override {
        bicycle->setMaxSpeed(speed);
    }

    void setWheels(int number) override {
        bicycle->setWheels(number);
    }

    Bicycle getResult() {
        return *bicycle;
    }
};

class Director {
private:
    unique_ptr<VehicleBuilder> builder;

public:
    void makeVehicle() {
        builder->reset();
    }

    void makeCar() {
        builder = make_unique<CarBuilder>();
        makeVehicle();
        builder->setMaxSpeed(200);
        builder->setWheels(4);
    }

    void makeBicycle() {
        builder = make_unique<BicycleBuilder>();
        makeVehicle();
        builder->setMaxSpeed(30);
        builder->setWheels(2);
    }

    unique_ptr<VehicleBuilder> getResult() {
        return move(builder);
    }
};

int main() {
    Director director;

    director.makeCar();
    Car car = dynamic_cast<Car&>(*director.getResult());
    cout << "Xe ô tô được tạo: " << car.toString() << endl;

    director.makeBicycle();
    Bicycle bicycle = dynamic_cast<Bicycle&>(*director.getResult());
    cout << "Xe đạp được tạo: " << bicycle.toString() << endl;

    return 0;
}

