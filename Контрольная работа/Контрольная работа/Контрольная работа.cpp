#include <iostream>
#include <string>
using namespace std;

/*
* autor: Valera Leontev
* 
* brief: The code was changed and a 
* new action was added in the form of
* the user indicating the initial size
* of the array, so that errors would not
* be repeated as at the beginning of adding
* objects to the array. the code was also
* completely translated into the English
* version for more convenient inspection
* of the code by the teacher
*/

class Furniture {
private:
    int weight;
    int width;
    int height;
    float price;
    string name;
    string color;

public:
    Furniture(int weight, float price, string name, string color, int width, int height) {
        this->weight = weight;
        this->price = price;
        this->name = name;
        this->color = color;
        this->width = width;
        this->height = height;
    }

    Furniture() {
        this->weight = 0;
        this->price = 0.0;
        this->name = "No Name";
        this->color = "No Color";
        this->width = 0;
        this->height = 0;
    }

    void OutputVoid() {
        cout << "Size: " << this->weight << endl
            << "Price: " << this->price << endl
            << "Name: " << this->name << endl
            << "Color: " << this->color << endl
            << "Width: " << this->width << endl
            << "Height: " << this->height << endl;
    }

    void RegainAccess(int weight, int width, int height) {
        this->weight = weight;
        this->width = width;
        this->height = height;
        this->price = weight * (width / height);

        cout << "For the entered components the price will be: " << this->price << endl;
    }

    float getPrice() const {
        return price;
    }

    string getName() const {
        return name;
    }
};

void sortFurniture(Furniture* objects[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (objects[j]->getPrice > objects[j + 1]->getPrice) {
                // Swap pointers
                Furniture* temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

void MenuUser() {
    int arraySize; // Максимальное количество объектов

    cout << "Before starting work, indicate what size tablet you want? :";
    cin >> arraySize;
    Furniture* objects_Fool[arraySize]; // Array of pointers to objects
    int index = 0; // Index to track the current number of objects
    bool isExit = false;
    int inputUser;

    while (!isExit) {
        cout << "__________________________________________________________________" << endl;
        cout << "Select an implementation to work with" << endl;
        cout << "[1] - Adding an empty object to an array\n"
            << "[2] - Adding an object with user - filled datan"
            << "[3] - Editing any field\n"
            << "[4] - Displaying information about all objects to the console\n"
            << "[5] - Sort an array\n"
            << "[6] - Terminating the program" << endl;
        cout << "__________________________________________________________________" << endl;

        cout << "Add: ";
        cin >> inputUser;

        int weight, width, height;
        float price;
        string name, color;

        switch (inputUser) {
        case 1:
            if (index < arraySize) {
                objects_Fool[index] = new Furniture(); // Adding an empty object
                index++;
                cout << "Empty object added." << endl;
            }
            else {
                cout << "The array is full!" << endl;
            }
            break;

        case 2:
            if (index < arraySize) {
                cout << "Enter object size: ";
                cin >> weight;
                cout << "Enter the price of the object: ";
                cin >> price;
                cout << "Enter object name: ";
                cin >> name;
                cout << "Enter object color: ";
                cin >> color;
                cout << "Enter object wibth: ";
                cin >> width;
                cout << "Enter object height: ";
                cin >> height;
                objects_Fool[index] = new Furniture(weight, price, name, color, width, height);
                index++;
            }
            else {
                cout << "The array is full!" << endl;
            }
            break;

        case 3:
            int editIndex;
            cout << "Enter the index of the object to edit(from 0 to " << index - 1 << "): ";
            cin >> editIndex;

            if (editIndex >= 0 && editIndex < index) {
                cout << "Enter a new size for the object: ";
                cin >> weight;
                cout << "Enter a new price for the item ";
                cin >> price;
                cout << "Enter a new name for the object: ";
                cin >> name;
                cout << "Enter a new color for yhe object: ";
                cin >> color;
                cout << "Enter a new wibth for the object: ";
                cin >> width;
                cout << "Enter a new height for the object: ";
                cin >> height;

                delete objects_Fool[editIndex]; // Delete a old object
                objects_Fool[editIndex] = new Furniture(weight, price, name, color, width, height); // Create a new object
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;

        case 4:
            cout << "Output oll for the object:" << endl;
            for (int i = 0; i < index; i++) {
                if (objects_Fool[i] != nullptr) {
                    objects_Fool[i]->OutputVoid();
                    cout << "-----------------------------------" << endl;
                }
            }
            break;

        case 5:
            // Сортировка массива объектов по цене
            sortFurniture(objects_Fool, index);
            cout << "Array sorted by price." << endl;
            break;

        case 6:
            cout << "Thank you for using the program!" << endl;
            isExit = true;
            // Освобождаем память
            for (int i = 0; i < index; i++) {
                delete objects_Fool[i];
            }
            break;

        default:
            cout << "You entered something wrong! try again!" << endl;
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    const int SIZE = 3;

    Furniture User(13, 2000, "Crib", "red", 14, 17);
    Furniture User_One(23, 1000, "chair", "blue", 15, 20);
    Furniture User_Twoo(100, 15000, "table", "white", 80, 100);

    Furniture arrFurniture[SIZE] = { User, User_One, User_Twoo };

    cout << endl;
    MenuUser();

}

