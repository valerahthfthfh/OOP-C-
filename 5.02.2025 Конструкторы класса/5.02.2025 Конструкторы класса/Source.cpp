#include <iostream>
#include <string>

using namespace std;

class Character {
private:

    const int size = 3;
    string* arr�apabilities = new string[size];

    // "strength", "agility", "intelligence"
    
public:
    
    void RandomFonctionArr() {

        string arr�apabilitiesBild[] = { "strength", "agility", "intelligence" };

        for (int i = 0; i < this->size; i++) {
            arr�apabilities[i] = arr�apabilitiesBild[i];
        }
        int random = rand() % this->size;
        cout << "Ability: " << arr�apabilities[random] << endl;

        int arrCharacter[] = { 12, 32, 100 };

        cout << "Damage: " << arrCharacter[random];
       
    }

    ~Character() {

        delete[] arr�apabilities;
    }

};

int main() {
    Character UserCharacter;
    UserCharacter.RandomFonctionArr();
}
