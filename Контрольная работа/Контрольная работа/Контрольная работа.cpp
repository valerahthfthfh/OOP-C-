#include <iostream>
#include <string>
using namespace std;

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
        cout << "������: " << this->weight << endl
            << "����: " << this->price << endl
            << "��������: " << this->name << endl
            << "����: " << this->color << endl
            << "������: " << this->width << endl
            << "������: " << this->height << endl;
    }

    void RegainAccess(int weight, int width, int height) {
        this->weight = weight;
        this->width = width;
        this->height = height;
        this->price = weight * (width / height);

        cout << "�� ��������� ������������ ���� �����: " << this->price << endl;
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
                // ������ ������� ���������
                Furniture* temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

void MenuUser() {
    const int arraySize = 5; // ������������ ���������� ��������
    Furniture* objects_Fool[arraySize]; // ������ ���������� �� �������
    int index = 0; // ������ ��� ������������ �������� ���������� ��������
    bool isExit = false;
    int inputUser;

    while (!isExit) {
        cout << "__________________________________________________________________" << endl;
        cout << "�������� ���������� ��� ������" << endl;
        cout << "[1] - ���������� ������� ������� � �������\n"
            << "[2] - ���������� ������� � �������, ������������ �������������\n"
            << "[3] - �������������� ������ ����\n"
            << "[4] - ����� � ������� ���������� ��� ���� ��������\n"
            << "[5] - ���������� �������\n"
            << "[6] - ���������� ������ ���������" << endl;
        cout << "__________________________________________________________________" << endl;

        cout << "����: ";
        cin >> inputUser;

        int weight, width, height;
        float price;
        string name, color;

        switch (inputUser) {
        case 1:
            if (index < arraySize) {
                objects_Fool[index] = new Furniture(); // ��������� ������ ������
                index++;
                cout << "������ ������ ��������." << endl;
            }
            else {
                cout << "������ �����!" << endl;
            }
            break;

        case 2:
            if (index < arraySize) {
                cout << "������� ������ �������: ";
                cin >> weight;
                cout << "������� ���� �������: ";
                cin >> price;
                cout << "������� �������� �������: ";
                cin >> name;
                cout << "������� ���� �������: ";
                cin >> color;
                cout << "������� ������ �������: ";
                cin >> width;
                cout << "������� ������ �������: ";
                cin >> height;
                objects_Fool[index] = new Furniture(weight, price, name, color, width, height);
                index++;
            }
            else {
                cout << "������ �����!" << endl;
            }
            break;

        case 3:
            int editIndex;
            cout << "������� ������ ������� ��� �������������� (�� 0 �� " << index - 1 << "): ";
            cin >> editIndex;

            if (editIndex >= 0 && editIndex < index) {
                cout << "������� ����� ������ �������: ";
                cin >> weight;
                cout << "������� ����� ���� �������: ";
                cin >> price;
                cout << "������� ����� �������� �������: ";
                cin >> name;
                cout << "������� ����� ���� �������: ";
                cin >> color;
                cout << "������� ����� ������ �������: ";
                cin >> width;
                cout << "������� ����� ������ �������: ";
                cin >> height;

                delete objects_Fool[editIndex]; // ������� ������ ������
                objects_Fool[editIndex] = new Furniture(weight, price, name, color, width, height); // ������� ����� ������
            }
            else {
                cout << "�������� ������!" << endl;
            }
            break;

        case 4:
            cout << "����� ���� ��������:" << endl;
            for (int i = 0; i < index; i++) {
                if (objects_Fool[i] != nullptr) {
                    objects_Fool[i]->OutputVoid();
                    cout << "-----------------------------------" << endl;
                }
            }
            break;

        case 5:
            // ���������� ������� �������� �� ����
            sortFurniture(objects_Fool, index);
            cout << "������ ������������ �� ����." << endl;
            break;

        case 6:
            cout << "�������, ��� ��������������� ����������!" << endl;
            isExit = true;
            // ����������� ������
            for (int i = 0; i < index; i++) {
                delete objects_Fool[i];
            }
            break;

        default:
            cout << "�� ����� ���-�� �� ��! ���������� ��� ���!" << endl;
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

