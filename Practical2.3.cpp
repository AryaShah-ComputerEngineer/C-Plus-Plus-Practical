#include<iostream>
using namespace std;
class accounts{
  long account_number;
  string name;
  long long balance;
  int pin;
  public:
void new_account();
void withdraw();
void deposit();
bool verify_pin(int temp_pin);
void check_balance();
int get_Acc_number();
};
void accounts::new_account()
{
    cout<<"Enter the name "<<endl;
    getline(cin,name);
    cout<<"Enter the account_number"<<endl;
    cin>>account_number;
    cout<<"Enter the balance you want"<<endl;
    cin>>balance;
    cout<<"Enter the 4 digit pin"<<endl;
    cin>>pin;
}

int accounts::get_Acc_number()
{
    return account_number;
}

void  accounts::withdraw()
{
    int amount=0;
    cout<<"Enter the amount to be withdraw"<<endl;
    cin>>amount;
    if(amount>balance)
    {
        cout<<"Insufficient balance"<<endl;

    }else{
        balance-=amount;
    }
}


void accounts::deposit()
{
 int amount=0;
    cout<<"Enter the amount to be withdraw"<<endl;
    cin>>amount;
    if(amount<=0)
    {
        cout<<"Invalid amoutn entered"<<endl;

    }else{
        balance+=amount;
    }
}


void accounts::check_balance()
{
    cout<<"The balance available in the account is "<<balance<<endl;
    cout<<"The account number is   "<<account_number<<endl;
}


bool accounts::verify_pin(int temp_pin)
{
    return temp_pin==pin;
}

int main()
{

    int choice,flag=0,i=0;
    accounts acc[15];
    acc[0].new_account();
    flag++;
    cout<<"Details stored succesfully"<<endl;
    do{
    cout<<"Enter 1 for adding new account"<<endl<<"Enter 2 for withdraw"<<endl<<"Enter 3 for deposit"<<endl;
    cout<<"Enter 4 for checking details"<<endl<<"Enter 5 for exit the bank"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1: if(flag>15)
                {
                     cout<<"Insufficient space"<<endl;
                     break;
                }
                acc[flag].new_account();
                flag++;
                break;

        case 2:{ int temp_pin=0,temp_acc;
                cout << "Enter account number: ";
                cin >> temp_acc;

                bool found = false;

                for (int i = 0; i < flag; i++)
                {
                    if (acc[i].get_Acc_number() == temp_acc)
                    {
                        acc[i].withdraw();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Account not found!" << endl;

                break;
    }

        case 3: {   int temp_pin=0,temp_acc;
                cout << "Enter account number: ";
                cin  >> temp_acc;

                bool found = false;

                for (int i = 0; i < flag; i++)
                {
                    if (acc[i].get_Acc_number() == temp_acc)
                    {
                        acc[i].deposit();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Account not found!" << endl;

                break;
        }

        case 4:
        {
            int temp_account=0;
            cout<<"Enter the account number"<<endl;
            cin>>temp_account;
            bool found=false;
            for(int i =0;i<flag;i++)
            {
                if(acc[i].get_Acc_number()==temp_account)
                {
                    int temp_pin=0;
                    pin:
                    cout<<"Enter the pin"<<endl;
                    cin>>temp_pin;
                    if(acc[i].verify_pin(temp_pin))
                    {
                        acc[i].check_balance();
                    }else{
                        cout<<"Invalid Pin"<<endl;
                        goto pin;
                    }
                        found=true;
                        break;
                }
            }
                if(!found)
                {
                    cout<<"Account not found"<<endl;
                }
                break;
        }

        case 5: break;
        default: cout<<"Invalid choice try again"<<endl;

    }

    }while(choice!=5);
    return 0;
}
