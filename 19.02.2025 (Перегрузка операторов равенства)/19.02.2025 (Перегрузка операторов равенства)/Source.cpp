#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
	int x;
	int y;
	int z;

	int size;
	int* arr;

public:

	int GetX() { return x; }
	int GetY() { return y; }
	int GetZ() { return z; }

	void SetX(int value) { x = value; }
	void SetZ(int value) { z = value; }
	void SetY(int value) { y = value; }

	Point()
	{
		x = 0;
		y = 0;
		z = 0;

		size = 10;
		arr = new int[size];
	}

	Point(int x, int y, int z, int size)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->size = size;

		arr = new int[size];
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->size = other.size;

		this->arr = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}

	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->size = other.size;

		if (arr != nullptr)
		{
			delete[] arr;
		}

		this->arr = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}

		return *this;
	}

	Point& operator - (const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		temp.z = this->z - other.z;

		return temp;
	}
	bool operator < (const Point& other)
	{
		this->x < other.x;
		this->y < other.y;
		this->z < other.z;
		return ((this->x + this->y + this->z) < (other.x + other.y + other.z));

	}
	bool operator > (const Point& other)
	{
		this->x > other.x;
		this->y > other.y;
		this->z > other.z;
		return ((this->x + this->y + this->z) > (other.x + other.y + other.z));

	}
	Point& operator ++ ()
	{
		x++;
		y++;
		z++;
		return *this;
	}

	~Point()
	{
		delete[] arr;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");

	++a;
	++b;

	Point Number_One(1, 1, 1, 7);

	Point Number_Twoo(6, 3, 2, 8);
	Point Number_fre;

	cout << "чиссло x увеличенно в объекте a: " << Number_One.GetX() << endl;
	cout << "чиссло x увеличенно в объекте b: " << Number_Twoo.GetX() << endl;

	Number_fre = Number_One - Number_Twoo;
	cout << "a - b = " << Number_fre.GetX() << endl;

}