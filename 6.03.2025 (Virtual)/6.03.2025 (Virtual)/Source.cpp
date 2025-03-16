#include <iostream>

using namespace std;

class BaseEnemy {
private:
    int speed;
    int health;
    float damage;
public:
    int getSpeed() {
        return speed;
    }

    int getHealth() {
        return health;
    }

    float getDamage() {
        return damage;
    }

    BaseEnemy() {
        this->damage = 15;
        this->speed = 2;
        this->health = 100;
    }

    virtual void DoDamage() = 0;
    virtual void Die() = 0;
    virtual void ChasePlayer() = 0; 
    virtual ~BaseEnemy() {}
};

class Archer : public BaseEnemy {
private:
    float Crete;
public:
    Archer() {
        this->Crete = 1.2;
    }

    virtual void DoDamage() override {
        cout << "A blow was fired = " << getDamage() * Crete << endl;
    }

    virtual void Die() override {
        cout << "health = " << getHealth() << endl;
    }

    virtual void ChasePlayer() override {
        if (getHealth() <= 70) {
            cout << "you're tired" << endl;
        }
    }
};

class Peasant : public BaseEnemy {
private:
    float strength;
public:

    Peasant() {
        this->strength = 30;
    }

    virtual void DoDamage() override {
        cout << "A blow was fired = " << getDamage() + strength << endl;
    }

    virtual void Die() override {
        cout << "health = " << getHealth() << endl;
    }

    virtual void ChasePlayer() override {
        if (getHealth() <= 20) {
            cout << "you're tired" << endl;
        }
    }
};

int main() {
    BaseEnemy* archer = new Archer();
    archer->DoDamage();
    archer->Die();
    archer->ChasePlayer();

    BaseEnemy* peasant = new Peasant();
    peasant->DoDamage();
    peasant->Die();
    peasant->ChasePlayer();

    delete archer; 
    delete peasant; 

}
