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
        cout << "Размер: " << this->weight << endl
            << "Цена: " << this->price << endl
            << "Название: " << this->name << endl
            << "Цвет: " << this->color << endl
            << "Ширина: " << this->width << endl
            << "Высота: " << this->height << endl;
    }

    void RegainAccess(int weight, int width, int height) {
        this->weight = weight;
        this->width = width;
        this->height = height;
        this->price = weight * (width / height);

        cout << "По введенным составляющим цена будет: " << this->price << endl;
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
                // Меняем местами указатели
                Furniture* temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }
}

void MenuUser() {
    const int arraySize = 5; // Максимальное количество объектов
    Furniture* objects_Fool[arraySize]; // Массив указателей на объекты
    int index = 0; // Индекс для отслеживания текущего количества объектов
    bool isExit = false;
    int inputUser;

    while (!isExit) {
        cout << "__________________________________________________________________" << endl;
        cout << "Выберите реализацию для работы" << endl;
        cout << "[1] - Добавление пустого объекта к массиву\n"
            << "[2] - Добавление объекта с данными, заполненными пользователем\n"
            << "[3] - Редактирование любого поля\n"
            << "[4] - Вывод в консоль информации обо всех объектах\n"
            << "[5] - Сортировка массива\n"
            << "[6] - Завершение работы программы" << endl;
        cout << "__________________________________________________________________" << endl;

        cout << "Ввод: ";
        cin >> inputUser;

        int weight, width, height;
        float price;
        string name, color;

        switch (inputUser) {
        case 1:
            if (index < arraySize) {
                objects_Fool[index] = new Furniture(); // Добавляем пустой объект
                index++;
                cout << "Пустой объект добавлен." << endl;
            }
            else {
                cout << "Массив полон!" << endl;
            }
            break;

        case 2:
            if (index < arraySize) {
                cout << "Введите размер объекта: ";
                cin >> weight;
                cout << "Введите цену объекта: ";
                cin >> price;
                cout << "Введите название объекта: ";
                cin >> name;
                cout << "Введите цвет объекта: ";
                cin >> color;
                cout << "Введите ширину объекта: ";
                cin >> width;
                cout << "Введите высоту объекта: ";
                cin >> height;
                objects_Fool[index] = new Furniture(weight, price, name, color, width, height);
                index++;
            }
            else {
                cout << "Массив полон!" << endl;
            }
            break;

        case 3:
            int editIndex;
            cout << "Введите индекс объекта для редактирования (от 0 до " << index - 1 << "): ";
            cin >> editIndex;

            if (editIndex >= 0 && editIndex < index) {
                cout << "Введите новый размер объекта: ";
                cin >> weight;
                cout << "Введите новую цену объекта: ";
                cin >> price;
                cout << "Введите новое название объекта: ";
                cin >> name;
                cout << "Введите новый цвет объекта: ";
                cin >> color;
                cout << "Введите новую ширину объекта: ";
                cin >> width;
                cout << "Введите новую высоту объекта: ";
                cin >> height;

                delete objects_Fool[editIndex]; // Удаляем старый объект
                objects_Fool[editIndex] = new Furniture(weight, price, name, color, width, height); // Создаем новый объект
            }
            else {
                cout << "Неверный индекс!" << endl;
            }
            break;

        case 4:
            cout << "Вывод всех объектов:" << endl;
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
            cout << "Массив отсортирован по цене." << endl;
            break;

        case 6:
            cout << "Спасибо, что воспользовались программой!" << endl;
            isExit = true;
            // Освобождаем память
            for (int i = 0; i < index; i++) {
                delete objects_Fool[i];
            }
            break;

        default:
            cout << "Вы ввели что-то не то! Попробуйте еще раз!" << endl;
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

