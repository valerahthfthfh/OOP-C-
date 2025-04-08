#include <iostream>

using namespace std;

class ElectricVehicle {
private:
    int batteryLevel;

public:
    ElectricVehicle() {
        this->batteryLevel = 0;
    }

    void charge(int amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100;
    }

    void showBattery() {
        cout << "Current battery level: " << batteryLevel << "%" << endl;
    }
};

class LandTransport {
private:
    int speed;

public:
    LandTransport() {
        this->speed = 0;
    }

    void accelerate(int value) {
        speed += value;
        cout << "Accelerating. Current speed: " << speed << " km/h" << endl;
    }

    void brake(int value) {
        speed -= value;
        if (speed < 0) speed = 0;
        cout << "Braking. Current speed: " << speed << " km/h" << endl;
    }

    virtual void landMode() { 
        cout << "Land transport mode." << endl;
    }
};

class WaterTransport {
private:
    int depth;

public:
    WaterTransport() {
        this->depth = 0;
    }

    void dive(int value) {
        depth += value;
        cout << "Diving. Current depth: " << depth << " meters" << endl;
    }

    void surface(int value) {
        depth -= value;
        if (depth < 0) depth = 0;
        cout << "Surfacing. Current depth: " << depth << " meters" << endl;
    }

    virtual void waterMode() { 
        cout << "Water transport mode." << endl;
    }
};

class ElectricCar : public ElectricVehicle, public LandTransport {
public:
    void drive() {
        cout << "Driving the electric car." << endl;
    }

    void sail() {
        cout << "Electric car cannot sail!" << endl;
    }

    void landMode() override { 
        cout << "Electric car in land mode." << endl;
    }
};

class ElectricBoat : public ElectricVehicle, public WaterTransport {
public:
    void drive() {
        cout << "Electric boat cannot drive on land!" << endl;
    }

    void sail() {
        cout << "Sailing the electric boat." << endl;
    }

    void waterMode() override { 
        cout << "Electric boat in water mode." << endl;
    }
};

class AmphibiousVehicle : public ElectricBoat, public ElectricCar {
public:
    void switchToLandMode() {
        cout << "Switching to land mode." << endl;
        landMode(); 
    }

    void switchToWaterMode() {
        cout << "Switching to water mode." << endl;
        waterMode(); 
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle;
    amphibiousVehicle.accelerate(60);
    amphibiousVehicle.switchToWaterMode();
    amphibiousVehicle.dive(10);
    amphibiousVehicle.switchToLandMode();
    amphibiousVehicle.surface(5);
    amphibiousVehicle.brake(30);


}
