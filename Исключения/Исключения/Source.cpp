#include <iostream>

using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Error");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2;

    try {
        cout << "Enter the number: ";
        cin >> num1;

        
        if (cin.fail()) {
            throw invalid_argument("Error");
        }

        cout << "Enter number: ";
        cin >> num2;

        
        if (cin.fail()) {
            throw invalid_argument("Error");
        }

        double result = divide(num1, num2);
        cout << "Result: " << result << endl;

    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }
    catch (const exception& e) {
        cout << "An unexpected error: " << e.what() << endl; 
    }

}

