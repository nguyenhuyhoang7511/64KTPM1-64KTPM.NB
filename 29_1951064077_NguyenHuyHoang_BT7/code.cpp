#include <iostream>
#include <string>
using namespace std;

class IVehicle {
public:
    virtual double Speed() const = 0;
    virtual string Info() const = 0;
    virtual string getColor() const = 0;
    virtual ~IVehicle() = default;
};

class Car : public IVehicle {
public:
    double Speed() const override {
        return 120.0;
    }

    string Info() const override {
        return "Sedan Car";
    }

    string getColor() const override {
        return "Red";
    }
};

class Motorcycle : public IVehicle {
public:
    double Speed() const override {
        return 150.0;
    }

    string Info() const override {
        return "Sport Bike";
    }

    string getColor() const override {
        return "Blue";
    }
};

class VehicleAbstraction {
protected:
    IVehicle* vehicle;

public:
    VehicleAbstraction(IVehicle* vehicle) : vehicle(vehicle) {}

    virtual double getSpeed() const {
        return vehicle->Speed();
    }

    virtual string getInfo() const {
        return vehicle->Info();
    }

    string getColor() const {
        return vehicle->getColor();
    }
};

class AdvancedVehicle : public VehicleAbstraction {
private:
    string premiumColor;

public:
    AdvancedVehicle(IVehicle* vehicle) : VehicleAbstraction(vehicle), premiumColor("Metallic") {}

    double getSpeed() const override {
        return vehicle->Speed() * 1.2;
    }

    string getInfo() const override {
        return vehicle->Info() + " (Premium)";
    }

    string getPremiumColor() const {
        return premiumColor + " " + vehicle->getColor();
    }
};

void printVehicleInfo(const VehicleAbstraction& vehicle) {
    cout << "Vehicle: " << vehicle.getInfo() << endl;
    cout << "Speed: " << vehicle.getSpeed() << " km/h" << endl;
    cout << "Color: " << vehicle.getColor() << endl;
}

int main() {
    IVehicle* car = new Car();
    IVehicle* bike = new Motorcycle();

    cout << "Basic Vehicles" << endl;
    VehicleAbstraction basicCar(car);
    VehicleAbstraction basicBike(bike);

    printVehicleInfo(basicCar);
    printVehicleInfo(basicBike);

    cout << "\nAdvanced Vehicles" << endl;
    AdvancedVehicle premiumCar(car);
    AdvancedVehicle premiumBike(bike);

    printVehicleInfo(premiumCar);
    printVehicleInfo(premiumBike);
    cout << "Premium Car Color: " << premiumCar.getPremiumColor() << endl;
    cout << "Premium Bike Color: " << premiumBike.getPremiumColor() << endl;

    delete car;
    delete bike;

    return 0;
}

