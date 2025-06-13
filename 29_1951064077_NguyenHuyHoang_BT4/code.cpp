#include <iostream>
#include <memory>
using namespace std;

class ICar {
public:
    virtual void output() const = 0;  
    virtual ~ICar() = default;     
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

class IBicycle {
public:
    virtual void output() const = 0;  
    virtual ~IBicycle() = default;    
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

class VehicleFactory {
public:
    virtual unique_ptr<ICar> createCar() const = 0;       
    virtual unique_ptr<IBicycle> createBicycle() const = 0; 
    virtual ~VehicleFactory() = default;  
};

class VNFactory : public VehicleFactory {
public:
    unique_ptr<ICar> createCar() const override {
        return make_unique<VNCar>();  
    }

    unique_ptr<IBicycle> createBicycle() const override {
        return make_unique<VNBicycle>();  
    }
};

class CNFactory : public VehicleFactory {
public:
    unique_ptr<ICar> createCar() const override {
        return make_unique<CNCar>();  
    }

    unique_ptr<IBicycle> createBicycle() const override {
        return make_unique<CNBicycle>();  
    }
};


class Client {
private:
    unique_ptr<VehicleFactory> factory;  

public:
    Client(unique_ptr<VehicleFactory> factory) : factory(move(factory)) {}

    void someOperation() const {
        auto car = factory->createCar();  
        auto bicycle = factory->createBicycle();  

        car->output();  
        bicycle->output();  
    }
};

int main() {
    cout << "== Việt Nam Factory ==" << endl;
    Client clientVN(make_unique<VNFactory>());
    clientVN.someOperation();  /

    cout << "\n== China Factory ==" << endl;
    Client clientCN(make_unique<CNFactory>());
    clientCN.someOperation();  

    return 0;
}
