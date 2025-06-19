#include <iostream>
#include <memory>
using namespace std;


class AnimalBuilder {
public:
    virtual void reset() = 0;
    virtual void setSound(const string& sound) = 0;
    virtual void setLegs(int number) = 0;
    virtual ~AnimalBuilder() = default;
};


class Dog {
private:
    string sound;
    int legs;

public:
    string getSound() const { return sound; }
    int getLegs() const { return legs; }

    void setSound(const string& sound) { this->sound = sound; }
    void setLegs(int legs) { this->legs = legs; }

    string toString() const {
        return "Dog{sound=" + sound + ", legs=" + to_string(legs) + "}";
    }
};


class Cat {
private:
    string sound;
    int legs;

public:
    string getSound() const { return sound; }
    int getLegs() const { return legs; }

    void setSound(const string& sound) { this->sound = sound; }
    void setLegs(int legs) { this->legs = legs; }

    string toString() const {
        return "Cat{sound=" + sound + ", legs=" + to_string(legs) + "}";
    }
};


class DogBuilder : public AnimalBuilder {
private:
    unique_ptr<Dog> dog;

public:
    DogBuilder() : dog(make_unique<Dog>()) {}

    void reset() override {
        dog = make_unique<Dog>();
    }

    void setSound(const string& sound) override {
        dog->setSound(sound);
    }

    void setLegs(int number) override {
        dog->setLegs(number);
    }

    Dog getResult() {
        return *dog;
    }
};


class CatBuilder : public AnimalBuilder {
private:
    unique_ptr<Cat> cat;

public:
    CatBuilder() : cat(make_unique<Cat>()) {}

    void reset() override {
        cat = make_unique<Cat>();
    }

    void setSound(const string& sound) override {
        cat->setSound(sound);
    }

    void setLegs(int number) override {
        cat->setLegs(number);
    }

    Cat getResult() {
        return *cat;
    }
};


class Director {
private:
