#include <iostream>
using namespace std;

struct SortStats {
    int comparisons;
    int swaps;
};

// sort an insert
SortStats insert(int arr[], int SIZE) {
    SortStats stats = { 0, 0 };

    for (int i = 1; i < SIZE; i++) {
        int main = arr[i];
        int j = i - 1;

        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > main) {
                arr[j + 1] = arr[j];
                stats.swaps++;
                j--;
            }
            else {
                break;
            }
        }
        arr[j + 1] = main;
        if (j + 1 != i) {
            stats.swaps++;
        }
    }
    return stats;
}

// sort a choice
SortStats choice(int arr[], int SIZE) {
    SortStats stats = { 0, 0 };

    for (int i = 0; i < SIZE - 1; i++) {
        int MIN = i;

        for (int j = i + 1; j < SIZE; j++) {
            stats.comparisons++;
            if (arr[j] < arr[MIN]) {
                MIN = j;
            }
        }

        if (MIN != i) {
            int temp = arr[i];
            arr[i] = arr[MIN];
            arr[MIN] = temp;
            stats.swaps++;
        }
    }
    return stats;
}

void print(int arr[], int SIZE) { // its output a function 
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 7;
    int arr_one[SIZE] = { 52, 20, 19, 3, 19, 17, 100 };
    int arr_two[SIZE] = { 52, 20, 19, 3, 19, 17, 100 };

    cout << "Original array: ";
    print(arr_one, SIZE);
    cout << endl;

    SortStats insertStats = insert(arr_one, SIZE);
    cout << "Sort from insert: ";
    print(arr_one, SIZE);
    cout << "Comparisons: " << insertStats.comparisons << endl;
    cout << "Swaps: " << insertStats.swaps << endl;
    cout << "Total operations: " << insertStats.comparisons + insertStats.swaps << endl;
    cout << endl;

  
    SortStats choiceStats = choice(arr_two, SIZE);
    cout << "Sort from choice: ";
    print(arr_two, SIZE);
    cout << "Comparisons: " << choiceStats.comparisons << endl;
    cout << "Swaps: " << choiceStats.swaps << endl;
    cout << "Total operations: " << choiceStats.comparisons + choiceStats.swaps << endl;
    cout << endl;

    
    cout << "Insertion sort vs Selection sort:" << endl;
    cout << "Comparisons: " << insertStats.comparisons << " vs " << choiceStats.comparisons;
    if (insertStats.comparisons < choiceStats.comparisons) {
        cout << " (Insertion wins)" << endl;
    }
    else if (insertStats.comparisons > choiceStats.comparisons) {
        cout << " (Selection wins)" << endl;
    }
    else {
        cout << " (Equal)" << endl;
    }

    cout << "Swaps: " << insertStats.swaps << " vs " << choiceStats.swaps;

    if (insertStats.swaps < choiceStats.swaps) {
        cout << " (Insertion wins)" << endl;
    }
    else if (insertStats.swaps > choiceStats.swaps) {
        cout << " (Selection wins)" << endl;
    }
    else {
        cout << " (Equal)" << endl;
    }

    cout << "Total operations: " << insertStats.comparisons + insertStats.swaps << " vs " << choiceStats.comparisons + choiceStats.swaps;

    if (insertStats.comparisons + insertStats.swaps < choiceStats.comparisons + choiceStats.swaps) {
        cout << " (Insertion wins)" << endl;
    }
    else if (insertStats.comparisons + insertStats.swaps > choiceStats.comparisons + choiceStats.swaps) {
        cout << " (Selection wins)" << endl;
    }
    else {
        cout << " (Equal)" << endl;
    }

}

