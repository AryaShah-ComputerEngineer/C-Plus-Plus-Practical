#include <iostream>
using namespace std;

class Employee {
    string name;
    float basicSalary;
    float bonus;

public:
    
    Employee() {
        name = "Unknown";
        basicSalary = 0;
        bonus = 1000; 
    }

    
    Employee(string n, float bSalary, float b) {
        name = n;
        basicSalary = bSalary;
        bonus = b;
    }

    
    inline float calculateTotalSalary() {
        return basicSalary + bonus;
    }

    
    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    
    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        string name;
        float basicSalary, bonus;
        int choice;

        cout << "\nEnter details for employee " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Basic Salary: ";
        cin >> basicSalary;

        cout << "Use default bonus? (1 = Yes, 0 = No): ";
        cin >> choice;

        if (choice == 1) {
            emp[i] = Employee(name, basicSalary, 1000); // default bonus
        } else {
            cout << "Enter bonus: ";
            cin >> bonus;
            emp[i] = Employee(name, basicSalary, bonus);
        }
    }

    
    cout << "\nEmployee Details:\n";
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    
    delete[] emp;

    return 0;
}