#include <iostream>
#include <string>

/*
* author: Valera
* 
* brief: The essence of the code is to learn 
* how to work correctly with staticom, which
* I certainly succeeded in doing.
* In the case of code and its execution,
* I only encountered the problem of correctly
* placing static functions, but there were no problems.
* The code performs all actions in the task.
* and created our own implementation of
* receiving damage and causing damage
*/

using namespace std;

class CombatUnit {
private:
    float health; // Rows with data (In the future there will be an implementation!)
    float damage;
    string UnitType;

    // For static fields
    int Resources;
    int CombatPower;

public:
    // Static fields
    static int ArmyResources;
    static int ArmyCombatPower;

    // Constructor without parameters
    CombatUnit() {
        this->health = 100.00;
        this->damage = 10.00;
        this->UnitType = "Tank";

        this->Resources = ArmyResources;
        this->CombatPower = ArmyCombatPower;
    }

    // Constructor with parameters
    CombatUnit(float health, float damage, string UnitType) {
        this->health = health;
        this->damage = damage;
        this->UnitType = UnitType;

        this->Resources = ArmyResources;
        this->CombatPower = ArmyCombatPower;
    }

    // Getters
    float GetHealth() { return health; }
    float GetDamage() { return damage; }
    string GetUnitType() { return UnitType; }

    static int GetArmyResources() { return ArmyResources; }
    static int GetArmyCombatPower() { return ArmyCombatPower; }

    // Setters
    void SetHealth(float value) { health = value; }
    void SetDamage(float value) { damage = value; }
    void SetUnitType(string value) { UnitType = value; }

    static void SetArmyResources(int value) { ArmyResources = value; }
    static void SetArmyCombatPower(int value) { ArmyCombatPower = value; }

    void CombatPowerDamageFunction() {

        int sum;
        if (CombatPower == 1 || CombatPower <= 20) {
            sum = CombatPower * damage - 3;

            cout << "Powers: " << UnitType << " inflicted: " << sum << endl;
        }
        else if (CombatPower == 21 || CombatPower <= 50) {
            sum = CombatPower * damage + 13;
            cout << "Powers: " << UnitType << " inflicted: " << sum << endl;
        }
        else {
            cout << "Sorry, you don't have enough money for a large army" << endl;
        }
    }

    void DamageTakenCounting(int EnemyDamage) {
        string OutputUser;

        int Enemy = health - EnemyDamage;

        cout << "You received this much damage: " << Enemy << endl;

        health = Enemy;

        cout << "You want? get treatment Yes[Y] No[N]: ";
        cin >> OutputUser;

        if (OutputUser == "Y") {
            int treatment = ArmyResources + health;

            if (ArmyResources <= 0) {
                cout << "It is not possible to do treatment because there is nothing" << endl;
            }
            else {
                health = treatment;
                cout << "Your health is equal to: " << health << endl;
            }

        }
        else {
            cout << "It's your decision" << endl;
        }
    }
};

// Initializing Static Fields
int CombatUnit::ArmyResources = 10;
int CombatUnit::ArmyCombatPower = 30;

int main() {
    CombatUnit Output; // Creating an Object

    // Function for calculating damage from the total number of the army
    Output.CombatPowerDamageFunction();

    // Damage function
    Output.DamageTakenCounting(30);
}
