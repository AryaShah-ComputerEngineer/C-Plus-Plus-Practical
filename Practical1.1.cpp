#include<iostream>
using namespace std;

class bank_acc
{
    float balance,amount_w,amount_a;
    string name;

     public:
         int acc_no;
         void create_acc()
    {
        cout<<"Enter the name:";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the bank account number:";
        cin>>acc_no;
        cout<<"Enter the balance:";
        cin>>balance;

    }
    void  withdraw(int acc_no)
    {
        cout<<"Enter the amount you want to withdraw:";
        cin>>amount_w;
        balance-=amount_w;
        cout<<"The left balance is:"<<balance;
    }
    void deposit(int acc_no)
    {
        cout<<"Enter the amount you want to deposit:";
        cin>>amount_a;
        balance+=amount_a;
        cout<<"The left balance is:"<<balance;
    }
    void check_balance(int acc_no)
    {
        cout<<"Your current balance is:"<<balance;
    }
};

int main()
{
    int no,acc_num,i;
    class bank_acc b[i];
    for(i=0;i<10;i++)
    {
    start:
    cout<<"\nFor creating the account press 1."<<endl<<"For withdrawing press 2."<<endl<<"For deposit press 3."<<endl<<"For checking the balance press 4."<<endl<<"If you want to exit than press 5.\n ";
    cin>>no;
    switch(no)
        {
        case 1:
            {
                b[i].create_acc();
                goto start;
            }

        case 2:
            {
                cout<<"Enter the bank account number:";
                cin>>acc_num;
                if(b[i].acc_no==acc_num)
                {
                    //calling object=b[i]
                    b[i].withdraw(acc_num);
                    goto start;
                }

                else
                {
                    cout<<"Your account number does not match!\n";
                    goto start;
                }
            }

        case 3:
            {
            cout<<"Enter the bank account number:";
            cin>>acc_num;
            if(b[i].acc_no==acc_num)
            {
                b[i].deposit(acc_num);
                goto start;
            }
            else
            {
                cout<<"Your account number does not match!\n";
                goto start;
            }
            }
        case 4:
            {
                cout<<"Enter the bank account number:";
                cin>>acc_num;
                if(b[i].acc_no==acc_num)
                {
                    b[i].check_balance(acc_num);
                }
            }
        case 5:
            {
                cout<<"\nThank you for checking the bank details.\n";
                goto down;
            }

        }
        down:
            break;
    }
return 0;
}
