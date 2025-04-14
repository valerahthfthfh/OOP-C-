#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Observer {
public:
    virtual void update(const string& message) = 0;
};

class Teacher {
private:
    vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const string& message) {
        for (int i = 0; i < observers.size(); i++) {
            observers[i]->update(message);
        }
    }

    void WrapUp() {
        notify("You can pack up and go home!");
    }
};

class Student_one : public Observer {
protected:
    string name;

public:
    Student_one(const string& name) {
        this->name = name;
    }
};

class Student_twoo : public Student_one {
public:
    Student_twoo(const string& name) : Student_one(name) {}

    void update(const string& message) override {
        cout << name << " starts packing things" << endl;
    }
};

class Student_tree : public Student_one {
public:
    Student_tree(const string& name) : Student_one(name) {}

    void update(const string& message) override {
        cout << name << " turns off the computer" << endl;
    }
};

class Student_four : public Student_one {
public:
    Student_four(const string& name) : Student_one(name) {}

    void update(const string& message) override {
        cout << name << " assembles a laptop" << endl;
    }
};
// i use gpt ----- litl, i dont know using
/*
* I didn't really understand it,
* after I watched the video on YouTube,
* I understood it, but I couldn't repeat it
*/
int main() {
    Teacher teacher;

    Student_twoo student1("Sanya");
    Student_tree student2("Artem");
    Student_four student3("Valera");

    teacher.attach(&student1);
    teacher.attach(&student2);
    teacher.attach(&student3);

    teacher.WrapUp();

}

