#include <iostream>

using namespace std;

class Pudge
{
private:
	int Health = 100;
	int Armour = 100;

public:

	void FreshMeat(int HealthVaule, int ArmourVaule) {

		Health = HealthVaule + Health;
		Armour = ArmourVaule + Armour;

	}

	void Output() {
		cout << Health << endl;
		cout << Armour << endl;
	}
};


int main() {

	Pudge outputGame;

	outputGame.FreshMeat(20, 52);
	outputGame.Output();
}