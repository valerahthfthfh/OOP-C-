#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    int number;

    cout << "Enter the number of pointers: ";
    cin >> number;

    if (number <= 0) {
        cout << "Eror" << endl;
        return 1;
    }
    
    auto sharedObject = make_shared<int>(42); 

    vector<shared_ptr<int>> pointers;

    for (int i = 0; i < number; i++) {
        pointers.push_back(sharedObject); 
    }

    for (int i = 0; i < number; i++) {
        cout << i + 1 << ": " << pointers[i].get() << endl; 
    }

}
