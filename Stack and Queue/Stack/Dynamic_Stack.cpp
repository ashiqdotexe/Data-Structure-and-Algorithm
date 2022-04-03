#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node()
    {
        value=0;
        next=NULL;
    }
    Node(int value)
    {
        this->value=value;
        next=NULL;
    }
};
class Stack
{
    public:
    Node* top;
    Stack()
    {
        top=NULL;
    }
    Stack(Node* newNode)
    {
        top=newNode;
    }
    Node* makeNode(int val)
    {
        Node* temp=new Node();
        temp->value=val;
        temp->next=NULL;
        return temp;
    }
    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        Node* temp=makeNode(val);
        if(top==NULL)
        {
            top=temp;
        }
        else
        {
            Node* ptr=top;
            top=temp;
            temp->next=ptr;
        }
    }
    Node* pop()
    {
        Node* temp=NULL;
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return temp;
        }
        else
        {
            temp=top;
            top=top->next;
            return temp;
        }
    }
    int Top()
    {
        Node* temp=top;
        if(isEmpty())
        {
            cout<<"Stack underflow";
            return temp->value;
        }
        else
        {
            return temp->value;
        }
    }
    int count()
    {
        int cnt=0;
        Node*temp=top;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void display()
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Stack s;
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }
    s.display();
    s.pop();
    s.display();
    cout<<"\nTOP element is: "<<s.Top()<<"\nTotal number of elements: "<<s.count()<<"\n";
}