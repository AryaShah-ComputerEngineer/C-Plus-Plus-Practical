#include<iostream>
#include<string>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    string num;
    int k;
    int sum1 = 0, sum2 = 0;

    cout << "Enter the num: ";
    cin >> num;

    cout << "Enter how many times you want to concatenate the string: ";
    cin >> k;

    string result = "";

    
    for(int i = 0; i < k; i++)
    {
        result += num;
    }

    cout << "Result: " << result << endl;

    
    for(int i = 0; i < result.length(); i++)
    {
        sum1 += (result[i] - '0');
    }

    
    if(sum1 < 10)
    {
        cout << "FINAL SUM: " << sum1 << endl;
    }
    else
    {
        
        string temp = to_string(sum1);

        for(int i = 0; i < temp.length(); i++)
        {
            sum2 += (temp[i] - '0');
        }

        cout << "FINAL SUM: " << sum2 << endl;
    }

    return 0;
}