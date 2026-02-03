#include<iostream>
using namespace std;

class library{
  int ID;
  string title,author;
  int copies;
  public:
      void add();
      int get_id();
      void change_count();
      void return_count();
      void display();
};

void library::display()
{
    cout<<"The name of the author is "<<author<<endl;
    cout<<"The title of the author is "<<title<<endl;
    cout<<"The available count of the book is "<<copies<<endl;
}
void library:: return_count()
{
    copies+=1;
}
void library:: change_count(){
    copies-=1;
}
int library::get_id()
{
    return ID;
}
void library::add()
{
    cout<<"Enter the book ID"<<endl;
    cin>>ID;
    cout<<"Enter the title"<<endl;
    cin.ignore();
    getline(cin,title);
    cout<<"Enter the author"<<endl;
    cin.ignore();
    getline(cin,author);
    cout<<"Enter the copies"<<endl;
    cin>>copies;
    }
int main()
{
    library book[20];
    int choice=0;
    int flag=0;
    do
    {
        start:
        cout<<"\nEnter 1 for adding new book"<<endl<<"Enter 2 for issuing the book"<<endl<<"Enter 3 for returning the book"<<endl;
        cout<<"Enter 4 for seeing the details" <<endl<<"Enter 5 for exit"<<endl;
        cin >>choice;

        switch(choice)
        {
            case 1:
                {
                    if(flag>=20)
                    {
                        cout<<"Invalid space"<<endl;
                        break;
                    }
                    book[flag].add();
                    flag++;
                    cout<<"Success"<<endl;
                    break;
                }
            case 2:
                {
                    int temp_id;
                    hell:
                    cout<<"Enter the id for the issueing the book"<<endl;
                    cin>>temp_id;
                    for(int i=0;i<flag;i++)
                    {
                        if(temp_id==book[i].get_id())
                        {
                            cout<<"Issued Success"<<endl;
                            book[i].change_count();
                        }
                        else
                        {
                            cout<<"The book ID you entered doesnt gets find.";
                            goto hell;
                        }
                    }
                    break;
                }
            case 3:
                {
                     int temp_id;
                    cout<<"Enter the id for the issueing the book"<<endl;
                    cin>>temp_id;
                    for(int i=0;i<flag;i++)
                    {
                        if(temp_id==book[i].get_id())
                        {
                            cout<<"Return Success"<<endl;
                            book[i].return_count();
                        }
                    }
                    break;
                }
            case 4:
                {
                    int temp_id;
                    cout<<"Enter the id for the issueing the book"<<endl;
                    cin>>temp_id;
                    for(int i=0;i<flag;i++)
                    {
                        if(temp_id==book[i].get_id())
                        {
                          book[i].display();
                        }
                    }
                }
        }

    }while(choice!=5);
    return 0;
}
