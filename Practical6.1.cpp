#include <iostream>
using namespace std;

class Circle {
protected:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }
};

class Area : public Circle {
public:
    void calculateArea() {
        float area = 3.14 * radius * radius;
        cout << "Area = " << area << endl;
    }
};

int main() {
    int n;
    float r;

    cout << "Enter number of inputs: ";
    cin >> n;

    Area obj;  

    for(int i = 0; i < n; i++) {
        cout << "\nEnter radius: ";
        cin >> r;

        obj.setRadius(r);     
        obj.calculateArea();   
    }

    return 0;
}