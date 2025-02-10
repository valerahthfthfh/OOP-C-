#include <iostream>
#include <string>

using namespace std;

class Character {
private:

    const int size = 3;
    string* arrÑapabilities = new string[size];

    // "strength", "agility", "intelligence"
    
public:
    
    void RandomFonctionArr() {

        string arrÑapabilitiesBild[] = { "strength", "agility", "intelligence" };

        for (int i = 0; i < this->size; i++) {
            arrÑapabilities[i] = arrÑapabilitiesBild[i];
        }
        int random = rand() % this->size;
        cout << "Ability: " << arrÑapabilities[random] << endl;

        int arrCharacter[] = { 12, 32, 100 };

        cout << "Damage: " << arrCharacter[random];
       
    }

    ~Character() {

        delete[] arrÑapabilities;
    }

};

int main() {
    Character UserCharacter;
    UserCharacter.RandomFonctionArr();
}
