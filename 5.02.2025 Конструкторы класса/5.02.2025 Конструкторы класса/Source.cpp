#include <iostream>
#include <string>

using namespace std;

class Character {
private:

    const int size = 3;
    string* arrŅapabilities = new string[size];

    // "strength", "agility", "intelligence"
    
public:
    
    void RandomFonctionArr() {

        string arrŅapabilitiesBild[] = { "strength", "agility", "intelligence" };

        for (int i = 0; i < this->size; i++) {
            arrŅapabilities[i] = arrŅapabilitiesBild[i];
        }
        int random = rand() % this->size;
        cout << "Ability: " << arrŅapabilities[random] << endl;

        int arrCharacter[] = { 12, 32, 100 };

        cout << "Damage: " << arrCharacter[random];
       
    }

    ~Character() {

        delete[] arrŅapabilities;
    }

};

int main() {
    Character UserCharacter;
    UserCharacter.RandomFonctionArr();
}
