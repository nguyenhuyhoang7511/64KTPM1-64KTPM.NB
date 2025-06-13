#include <iostream>
using namespace std;

class ICar {
public:
    virtual void output() const = 0;
    virtual ~ICar() = default;
};

class IBicycle {
public:
    virtual void output() const = 0;
    virtual ~IBicycle() = default;
};

class VehicleFactory {
public:
    virtual ICar* createCar() const = 0;
    virtual IBicycle* createBicycle() const = 0;
    virtual ~VehicleFactory() = default;
};

class VNCar : public ICar {
public:
    void output() const override {
        cout << "VNCar: Tốc độ tối đa là 200 km/h" << endl;
    }
};

class CNCar : public ICar {
public:
    void output() const override {
        cout << "CNCar: Tốc độ tối đa là 180 km/h" << endl;
    }
};

class VNBicycle : public IBicycle {
public:
    void output() const override {
        cout << "VNBicycle: Tốc độ tối đa là 30 km/h" << endl;
    }
};

class CNBicycle : public IBicycle {
public:
    void output() const override {
        cout << "CNBicycle: Tốc độ tối đa là 25 km/h" << endl;
    }
};

class VNFactory : public VehicleFactory {
public:
    ICar* createCar() const override {
        return new VNCar();
    }

    IBicycle* createBicycle() const override {
        return new VNBicycle();
    }
};

class CNFactory : public VehicleFactory {
public:
    ICar* createCar() const override {
        return new CNCar();
    }

    IBicycle* createBicycle() const override {
        return new CNBicycle();
    }
};

class Client {
private:
    VehicleFactory* factory;
public:
    Client(VehicleFactory* factory) : factory(factory) {}

    void someOperation() const {
        ICar* car = factory->createCar();
        IBicycle* bicycle = factory->createBicycle();

        car->output();
        bicycle->output();

        delete car;
        delete bicycle;
    }
};

int main() {
    cout << "== Việt Nam Factory ==" << endl;
    Client clientVN(new VNFactory());
    clientVN.someOperation();

    cout << "\n== China Factory ==" << endl;
    Client clientCN(new CNFactory());
    clientCN.someOperation();

    return 0;
}
