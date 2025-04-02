#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
private:
    const float P = 3.14; 
    float r; 

public:
    Shape() {
        this->r = 1; 
    }

    Shape(float r) {
        this->r = r; 
    }

    float getP() {
        return P; 
    }

    float getR() {
        return this->r; 
    }

    virtual void FooSquare() {
        float square = P * (pow(r, 2)); 
        cout << "The area of the circle is - " << square << endl;
    }

    static int generateId() {
        return ++lastId; 
    }

    int getId() {
        return generateId(); 
    }

    static void resetId() {
        lastId = 0; 
    }

    Shape& operator = (const Shape& other)
    {
        this->r = other.r;

        return *this;
    }

    Shape& operator + (const Shape& other)
    {
        Shape temp;
        temp.r = this->r - other.r;


        return temp;
    }

protected:
    static int lastId; 
};

int Shape::lastId = 0; 

class sphere : public Shape { 
public:
    sphere(float r) : Shape(r) {} 

    void FooSquare() override {
        float square = getP() * 4 * (pow(getR(), 2)); 
        cout << "The area of the sphere is - " << square << endl;
    }

    ~sphere() {
        
    }


};

class ellipse : public Shape { 
private:
    float a; 
    float b; 

public:
    ellipse() {
        this->a = 2; 
        this->b = 1;
    }

    ellipse(float a, float b) {
        this->a = a; 
        this->b = b;
    }

    void FooSquare() override {
        float square = getP() * a * b; 
        cout << "The area of the ellipse is - " << square << endl;
    }

    ~ellipse() {
        
    }
};

int main() {
    vector<Shape*> shapes; 

   
    shapes.push_back(new Shape(5)); 
    shapes.push_back(new sphere(3)); 
    shapes.push_back(new ellipse(4, 2)); 

    
    for (int i = 0; i < shapes.size(); i++) {
        cout << "ID: " << shapes[i]->getId() << " "; 
        shapes[i]->FooSquare(); 
    }

    // delete Shape
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i]; 
    }

    
}


//Point& operator = (const Point& other)
//{
//    this->x = other.x;
//    this->y = other.y;
//    this->z = other.z;
//    this->size = other.size;
//
//    if (arr != nullptr)
//    {
//        delete[] arr;
//    }
//
//    this->arr = new int[other.size];
//
//    for (int i = 0; i < other.size; i++)
//    {
//        this->arr[i] = other.arr[i];
//    }
//
//    return *this;
//}
//
//Point& operator - (const Point& other)
//{
//    Point temp;
//    temp.x = this->x - other.x;
//    temp.y = this->y - other.y;
//    temp.z = this->z - other.z;
//
//    return temp;
//}