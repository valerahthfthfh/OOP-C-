#include <iostream>
using namespace std;

struct VariablesList
{
    int data;
    VariablesList* next;

    VariablesList(int value) {
        
        this->data = value;
        this->next = nullptr;
    }
};

class List {
private:
    VariablesList* start;
    VariablesList* last;

public:
    List() {

        this->start = nullptr;
        this->last = nullptr;
    }

    void add(int value) {

        VariablesList* newElement = new VariablesList(value);

        if (start == nullptr)
            start = last = newElement;
        else {
            last->next = newElement;
            last = newElement;
        }
    }

    void print() {

        VariablesList* current = start;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    // Не забыть очистить

    ~List() {

        while (start != nullptr) {
            VariablesList* temp = start;
            start = start->next;
            delete temp;
        }
    }
};

int main()
{
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.print();
}

