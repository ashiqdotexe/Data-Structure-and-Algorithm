#include<bits/stdc++.h>
using namespace std;
class Complex
{
    friend Complex operator*(Complex,Complex);
    friend Complex operator*(Complex,int);
    friend Complex operator*(int,Complex);
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
    cout<<this->real<<"X"<<this->imagine<<"i"<<endl;
}
Complex operator*(Complex a, Complex b)
{
    Complex mul;
    mul.real=a.real*b.real;
    mul.imagine=a.imagine*b.imagine;
    return mul;
}
Complex operator*(Complex a, int b)
{
    Complex mul;
    mul.real=a.real*b;
    mul.imagine=a.imagine;
    return mul;
}
Complex operator*(int a, Complex b)
{
    Complex mul;
    mul.real=a*b.real;
    mul.imagine=b.imagine;
    return mul;
}
int main()
{
    Complex m1(2,4);
    Complex m2(6,5);
    Complex mul1,mul2,mul3;
    mul1=m2*m1;//12X20i
    mul2=m1*5;//10X4i
    mul3=20*m2;//120X5i
    mul1.print();
    mul2.print();
    mul3.print();
}