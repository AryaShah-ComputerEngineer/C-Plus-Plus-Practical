#include<iostream>
using namespace std;

class fueltype
{
protected:
    string fuel;
public:
    fueltype(string f)
    {
        fuel = f;
    }
};

class brandtype
{
protected:
    string brand;
public:
    brandtype(string b)
    {
        brand = b;
    }
};

class car : public fueltype, public brandtype
{
public:
    car(string f, string b) : fueltype(f), brandtype(b)
    {
    }

    void display_details()
    {
        cout << "The fuel type is: " << fuel << endl;
        cout << "The brand type is: " << brand << endl;
    }
};

int main()
{
    car c("PETROL", "CRETA");
    c.display_details();
    return 0;
}