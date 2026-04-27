#include<iostream>
#include<string>
using namespace std;

string name;

void add_at_last(string input)
{
    name += input;  
    cout << "Adding at last gives: " << name << endl;
}

void delete_between(int temp_index)
{
    if (temp_index >= 0 && temp_index < name.length())
    {
        name.erase(temp_index, 1);
        cout << "Deleting element gives: " << name << endl;
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

int main()
{
    string input;
    int num = 0;
    int temp_index;

    cout << "Enter the initial string:" << endl;
    getline(cin, name);

    while(num != 4)
    {
        cout << "\nMenu:\n";
        cout << "1. Add element to the end\n";
        cout << "2. Delete element from index\n";
        cout << "3. Display the current string\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> num;
        cin.ignore();

        switch(num)
        {
            case 1:
                cout << "Enter string to add: ";
                getline(cin, input);
                add_at_last(input); 
                break;

            case 2:
                cout << "Enter index to delete: ";
                cin >> temp_index;
                delete_between(temp_index);
                break;

            case 3:
                cout << "Current string: " << name << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}