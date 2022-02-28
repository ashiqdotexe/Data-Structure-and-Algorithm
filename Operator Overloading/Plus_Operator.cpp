#include<bits/stdc++.h>
using namespace std;
 
class Complex
{ 
friend Complex operator+(Complex, Complex);
friend Complex operator+(Complex, int);
friend Complex operator+(int, Complex);
private:
    int real, imaginary;
public:
    Complex();
    Complex(int,int);
    void Print();
};
 
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}
Complex::Complex(int r, int im)
{
    real = r;
    imaginary = im;
}
 
void Complex::Print()
{
    cout<<real<<"+"<<imaginary<<"i"<<endl;
}
 
Complex operator+(Complex a, Complex b)
{
    Complex sum;
    sum.real = a.real +b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    return sum;
}
Complex operator+(Complex a, int b)
{
    Complex sum;
    sum.real = a.real +b;
    sum.imaginary = a.imaginary;
    return sum;
}
 
Complex operator+(int a, Complex b)
{
    Complex sum;
    sum.real = a +b.real;
    sum.imaginary = b.imaginary;
    return sum;
}
 
int main()
{
    Complex c1(2,3);
    Complex c2(4,5);
    Complex sum;
    sum = c1+5;
    sum.Print();
    return 0;
}