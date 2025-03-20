#include <iostream>

using namespace std;

class IWorkNumbers {
public:
    virtual int count(int number) = 0;
};

class DigitCount : public IWorkNumbers {
public:

    virtual int count(int number) override {

        if (number < 0) {
            number = -number;
        }

        if (number == 0) {
            return 1;
        }

        int count = 0;
        while (number > 0) {
            number /= 10;
            count++;
        }

        return count;

    }
};

class Prime : public IWorkNumbers {
public:

    virtual int count(int number) override {
        if (number < 2) {
            return false;
        }

        for (int i = 2; i * i <= number; ++i) { // интернет
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

};

int main() {

    DigitCount output;

    int res;

    res = output.count(163434);

    cout << res;
}