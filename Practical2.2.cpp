#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks[3];

public:
    Student() {
        roll = 0;
        name = "Test";
        for (int i = 0; i < 3; i++)
            marks[i] = 0;
    }
    Student(int r, string n, float m[]) {
        roll = r;
        name = n;
        for (int i = 0; i < 3; i++)
            marks[i] = m[i];
    }

    float getAverage() {
        float sum = 0;
        for (int i = 0; i < 3; i++)
            sum += marks[i];
        return sum / 3;
    }

    void display(int choice) {
        if (choice == 1) {
            cout << "Roll No: " << roll << endl;
        }
        else if (choice == 2) {
            cout << "Name: " << name << endl;
        }
        else if (choice == 3) {
            cout << "Marks: ";
            for (int i = 0; i < 3; i++)
                cout << marks[i] << " ";
            cout << endl;
        }
        else if (choice == 4) {
            cout << "Average Marks: " << getAverage() << endl;
        }
        else if (choice == 5) {
            cout << "Roll No: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: ";
            for (int i = 0; i < 3; i++)
                cout << marks[i] << " ";
            cout << endl;
            cout << "Average Marks: " << getAverage() << endl;
        }
        cout << "------------------------\n";
    }
};

int main() {
    int z;
    cout << "Enter number of students: ";
    cin >> z;

    Student students[z];

    char choice;
    cout << "Do you want to enter user data? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        for (int i = 0; i < z; i++) {
            int roll;
            string name;
            float marks[3];

            cout << "\nEnter details for student " << i + 1 << endl;
            cout << "Roll Number: ";
            cin >> roll;
            cout << "Name: ";
            cin >> name;
            cout << "Enter marks of 3 subjects:\n";
            for (int j = 0; j < 3; j++)
                cin >> marks[j];

            students[i] = Student(roll, name, marks);
        }
    }

    int showChoice;
    cout << "\nWhat details do you want to display?\n";
    cout << "1. Roll Number\n";
    cout << "2. Name\n";
    cout << "3. Marks\n";
    cout << "4. Average Marks\n";
    cout << "5. All Details\n";
    cout << "Enter choice: ";
    cin >> showChoice;

    cout << "\nStudent Records:\n";
    for (int i = 0; i < z; i++) {
        students[i].display(showChoice);

    }

    return 0;

}
