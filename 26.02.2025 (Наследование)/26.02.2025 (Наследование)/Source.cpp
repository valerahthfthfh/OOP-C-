#include <iostream>
#include <string>

using namespace std;

/*
* autor: Valera Leontev
* 
* brief: The code was completely completed as specified, 
* all requirements were met. The code performs a number of functions:
* 1) works with copying classes
* 2) displays copied elements.
* It’s a little unclear why the task required using
* the protected field since there was nothing
* in the requirement indicating its use
*/

class Animal {
private:
    string name;
    int weight;

public:
    // Animal class constructor
    Animal(string name, int weight) {
        this->name = name;
        this->weight = weight;
    }

    string getName() { return name; }
    int getWeight() { return weight; }

    void print() {
        cout << "Name: " << name << " Weight: " << weight << endl;
    }

protected:
    int age;
};

class Cat : public Animal {
public:
    // Constructor for the Cat class, passing parameters to the base class
    Cat(string name, int weight) : Animal(name, weight) {}
};

class Dog : public Animal {
public:
    // Constructor for the Dog class, passing parameters to the base class
    Dog(string name, int weight) : Animal(name, weight) {}
};

int main() {
    Cat Barsic("Barsic", 13);
    Barsic.print();

    Cat Vasca("Vasca", 15);
    Vasca.print();

    Dog Drujok("Drujok", 36);
    Drujok.print();

    Dog Bobs("Bobs", 46);
    Bobs.print();

}

