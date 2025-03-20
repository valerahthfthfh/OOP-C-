#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    int numberWheels;
public:

    Vehicle(int numberWheels) {
        this->numberWheels = numberWheels;
    }

    int getnumberWheels() {
        return numberWheels;
    }

    virtual void log() = 0;
};

class Car : public Vehicle {
private:
    string model;
    int nubreFire;
public:
    Car(string model) : Vehicle(4) {
        this->model = model;
        this->nubreFire = 0;
    }

    void log() override {
        cout << "Car name: " << model << ", numer fire " << nubreFire << ", number Wheels " << getnumberWheels() << endl;
    }

    Car& operator ++ () {
        nubreFire++;

        return *this;
    }
};

class Bike : public Vehicle {
private:
    string name;
    int nubreFire;
public:
    Bike(string name) : Vehicle(2) {
        this->name = name;
        this->nubreFire = 1;
    }

    void log() override {
        cout << "Bike name: " << name << ", numer fire " << nubreFire << ", number Wheels " << getnumberWheels() << endl;
    }

    Bike& operator ++ () {
        nubreFire++;

        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    const int size = 3;
    Vehicle* vehicles[size];


    vehicles[0] = new Car("Toyota");
    vehicles[1] = new Car("Honda");
    vehicles[2] = new Bike("Mountain"); // it`s type Bice


    for (int i = 0; i < size; ++i) {
        vehicles[i]->log();
    }

    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }

}
