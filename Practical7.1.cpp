#include <iostream>
using namespace std;

class Calculator {
private:
    double results[100]; 
    int count;           

public:
    
    Calculator() {
        count = 0;
    }

    
    int add(int a, int b) {
        int result = a + b;
        results[count++] = result;
        return result;
    }

    
    float add(float a, float b) {
        float result = a + b;
        results[count++] = result;
        return result;
    }

    
    float add(int a, float b) {
        float result = a + b;
        results[count++] = result;
        return result;
    }

    
    float add(float a, int b) {
        float result = a + b;
        results[count++] = result;
        return result;
    }

    
    void displayResults() {
        cout << "\nStored Results:\n";
        for (int i = 0; i < count; i++) {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    
    cout << "Int + Int: " << calc.add(5, 10) << endl;
    cout << "Float + Float: " << calc.add(2.5f, 3.5f) << endl;
    cout << "Int + Float: " << calc.add(7, 2.3f) << endl;
    cout << "Float + Int: " << calc.add(4.2f, 6) << endl;

    
    calc.displayResults();

    return 0;
}