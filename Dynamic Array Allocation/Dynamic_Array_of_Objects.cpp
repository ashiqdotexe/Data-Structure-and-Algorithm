#include<bits/stdc++.h>
using namespace std;
class book
{
    private:
    int id;
    char name[20];
    public:
    void readName()
    {
        cout<<"Enter your name: ";
        cin.ignore();
        gets(name);
        cout<<"Enter your id: ";
        cin>>id;
    }
    void showName()
    {
        cout<<name<<"\t"<<id<<endl;
    }
};
int main()
{
    book *b;
    b=new book[3];
    for(int i=0;i<3;i++)
    {
        b[i].readName();
    }
    cout<<"Name"<<"\t"<<"ID"<<endl;
    for(int i=0;i<3;i++)
    {
        b[i].showName();
    }
    delete b;
    
}