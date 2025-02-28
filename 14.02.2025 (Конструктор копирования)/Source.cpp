#include <iostream>
#include <string>

using namespace std;

class DynamicArray
{
private:
	int* arr;
	int SIZE;
public:

	DynamicArray() {
		this->arr = new int[SIZE];
		this->SIZE = 5;

	}

	DynamicArray(int SIZE) {
		this->SIZE = SIZE;
		this->arr = new int[SIZE];
	}

	DynamicArray(const DynamicArray& other) {
		this->SIZE = other.SIZE;

		this->arr = new int[other.SIZE];
		for (int i = 0; i < other.SIZE; i++) {
			arr[i] = other.arr[i] + 1;
			cout << this->arr[i] << endl;
		}


	}

	void OutputArrey() {
		for (int i = 0; i < SIZE; i++) {
			arr[i] = rand() % 11;
		}
	}

	~DynamicArray() {
		delete[] arr;
	}

};


int main()
{
	setlocale(LC_ALL, "Ru");

	DynamicArray Output(8);

	Output.OutputArrey();
	DynamicArray copy(Output);
}