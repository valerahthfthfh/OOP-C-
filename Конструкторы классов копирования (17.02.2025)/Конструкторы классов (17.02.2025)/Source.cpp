#include <iostream>

using namespace std;

class Number {
private:
    int a;
    int b;

public:
    // baza
    Number(int a = 0, int b = 0) {
        this->a = a;
        this->b = b;
        cout << "Output: " << this << endl;
    }


    Number(const Number& other) {
        a = other.a + 1;  
        b = other.b + 1; 
        cout << "Output: " << this << endl;
    }

    void window() const {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    Number object_one(5, 5); 
    Number object_twoo = object_one;  


    object_one.window(); 
    object_twoo.window(); 


}

