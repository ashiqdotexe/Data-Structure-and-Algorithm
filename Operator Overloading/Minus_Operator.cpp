#include<bits/stdc++.h>
using namespace std;
class Complex
{
    friend Complex operator-(Complex,Complex);
    friend Complex operator-(Complex,int);
    friend Complex operator-(int,Complex);
    private:
    int real;
    int imagine;
    public:
    Complex();
    Complex(int,int);
    void print();
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
void Complex::print()
{
    cout<<this->real<<"-"<<this->imagine<<"i"<<endl;
}
Complex operator-(Complex a, Complex b)
{
    Complex sub;
    sub.real=a.real-b.real;
    sub.imagine=a.imagine-b.imagine;
    return sub;
}
Complex operator-(Complex a, int b)
{
    Complex sub;
    sub.real=a.real-b;
    sub.imagine=a.imagine;
    return sub;
}
Complex operator-(int a, Complex b)
{
    Complex sub;
    sub.real=a-b.real;
    sub.imagine=b.imagine;
    return sub;
}
int main()
{
    Complex m1(8,4);
    Complex m2(15,6);
    Complex sub1,sub2,sub3;
    sub1=m2-m1;//7-2i
    sub2=m1-5;//3-4i
    sub3=20-m2;//5-6i
    sub1.print();
    sub2.print();
    sub3.print();
}