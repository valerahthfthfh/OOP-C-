#include <iostream>

using namespace std;

class class_twoo; 

class class_one {
public:
    int number_one = 5;
    int number_two = 5;

    friend void SumNumberOll(class_one& value1, class_twoo& value2);
};

class class_twoo {
public:
    int number_tree = 6;
    int number_four = 6;

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
