#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void linearSearch(const int SIZE, const vector<int>& arr, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == num) {
            cout << "Linear found at index: " << i << endl;
            return; 
        }
    }
    cout << "Linear: not found" << endl; 
}

void binarySearch(const int SIZE, const vector<int>& arr, int num) {
    int left = 0;
    int right = SIZE - 1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            cout << "Binary found at index: " << mid << endl;
            return; 
        }
        else if (arr[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
}

void interpolationSearch(const int SIZE, const vector<int>& arr, int num) {
    int left = 0;
    int right = SIZE - 1; 

    while (left <= right && num >= arr[left] && num <= arr[right]) {
        if (left == right) {
            if (arr[left] == num) {
                cout << left << endl;
                return; 
            }
            break; 
        }

        // double чтобы избежать деления на 0
        int position = left + ((double)(num - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (position < left || position > right) {
            break;
        }

        if (arr[position] == num) {
            cout <<  position << endl;
            return;
        }
        else if (arr[position] < num) {
            left = position + 1;
        }
        else {
            right = position - 1;
        }
    }
    
}

int main()
{
    const int SIZE = 6;
    vector<int> arr = { 1, 2, 3, 1000, 50000, 1000000 };
    int searchNumber = 50000;

    cout << "Searching in small array:" << endl;
    linearSearch(SIZE, arr, searchNumber);
    binarySearch(SIZE, arr, searchNumber);
    interpolationSearch(SIZE, arr, searchNumber);

    //----

    const int SIZE_two = 1000000;
    vector<int> array(SIZE_two);

    iota(array.begin(), array.end(), 1);

    cout << "\nSearching in large array:" << endl;
    linearSearch(SIZE_two, array, searchNumber);
    binarySearch(SIZE_two, array, searchNumber);
    interpolationSearch(SIZE_two, array, searchNumber);

    
}