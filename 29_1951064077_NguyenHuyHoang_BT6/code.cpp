#include <iostream>
using namespace std;

class VehicleInterface {
public:
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual ~VehicleInterface() = default;
};

class CarService {
public:
    void pressGas() {
        cout << "CarService: Run !!!" << endl;
    }

    void hitBrakes() {
        cout << "CarService: Stop !!!" << endl;
    }
};

class CarServiceAdapter : public VehicleInterface {
private:
    CarService* adaptee;

public:
    CarServiceAdapter(CarService* service) : adaptee(service) {}

    void accelerate() override {
        adaptee->pressGas();
    }

    void brake() override {
        adaptee->hitBrakes();
    }
};

int main() {
    CarService carService;
    VehicleInterface* vehicle = new CarServiceAdapter(&carService);

    vehicle->accelerate();
    vehicle->brake();

    delete vehicle;
    return 0;
}
