#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=5;
    int* p=&x;
    cout<<p<<endl;
    cout<<*p<<endl;
    int **pp=&p;
    cout<<*pp<<endl;
    cout<<**pp<<endl;
    **pp=25;
    cout<<**pp<<endl;
    cout<<x<<endl;
    cout<<&x<<endl;
}