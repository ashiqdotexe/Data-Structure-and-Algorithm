#include<bits/stdc++.h>
using namespace std;
class Complex
{
    friend bool operator>(Complex,Complex);
    private:
    int real;
    int imagine;
    public:
    Complex();
    Complex(int,int);
    int getReal()
    {
       return real; 
    }
     int getImagine()
    {
       return imagine; 
    }
};
Complex::Complex()
{
    real=0;
    imagine=0;
}
Complex::Complex(int real, int imagine)
{
    this->real=real;
    this->imagine=imagine;
}
bool operator>(Complex a, Complex b)
{
    if((a.real>b.real) || (a.imagine>b.imagine))
    {
        return true;
    }
    return false;
}
int main()
{
    Complex e1(8,3);
    Complex e2(8,4);
    if(e1>e2)
    {
        cout<<"("<<e1.getReal()<<","<<e1.getImagine()<<")"<< " is greater than "<<"("<<e2.getReal()<<","<<e2.getImagine()<<")";
    }
    else cout<<"("<<e1.getReal()<<","<<e1.getImagine()<<")"<< " is less than "<<"("<<e2.getReal()<<","<<e2.getImagine()<<")";
}