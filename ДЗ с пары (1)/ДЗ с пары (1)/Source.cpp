#include <iostream>

using namespace std;

class class_twoo;

class class_one {
private:
    int number_one;
    int number_two;
public:

    class_one() {
        this->number_one = 5;
        this->number_two = 5;
    }

    class_one(int number_one, int number_two) {
        this->number_one = number_one;
        this->number_two = number_two;
    }

    friend void SumNumberOll(class_one& value1, class_twoo& value2);
};

class class_twoo {
private:
    int number_tree;
    int number_four;

public:

    class_twoo() {
        this->number_tree = 1;
        this->number_four = 4;
    }

    class_twoo(int number_tree, int number_four) {
        this->number_tree = number_tree;
        this->number_four = number_four;
    }

    friend void SumNumberOll(class_one& value1, class_twoo& value2);
};

void SumNumberOll(class_one& value1, class_twoo& value2) {
    int sum = value1.number_one + value1.number_two + value2.number_tree + value2.number_four;
    cout << "Sum: " << sum << endl;
}

int main() {
    class_one obj1;
    class_twoo obj2;

    SumNumberOll(obj1, obj2);

}
