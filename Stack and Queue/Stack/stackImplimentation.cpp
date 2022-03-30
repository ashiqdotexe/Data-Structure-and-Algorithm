#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int arr[100];
public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if (isFull())
            cout << "Already full";
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
            cout << "Already empty";
        else
        {
            int ptrvalue = arr[top];
            arr[top] = 0;
            top--;
            return ptrvalue;
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "already empty";
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "changed";
    }
    void Display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << "\n"<<arr[i] << endl;
        }
    }

};
int main()
{
    Stack s;
    Stack s1;
    int n1,n2,sum;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++)
    {
        int num;
        cin>>num;
        s.push(num);
    }
    for(int i=0;i<n2;i++)
    {
        int num;
        cin>>num;
        s1.push(num);
    }
    s.Display();
}
