#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};


class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id) {
        department = dept;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m("Rahul", 35, 101, "IT");
    m.displayDetails();
    return 0;
}