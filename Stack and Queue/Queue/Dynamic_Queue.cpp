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
    }
};
class Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
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
        if(rear==NULL && front==NULL)
        {
            return true;
        }
        else return false;
    }
    void enQueue(int val)
    {
        Node* temp=makeNode(val);
        if(front==NULL && rear==NULL)
        {
            front=temp;
            rear=temp;
            cout<<"Enqueued"<<endl;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
   Node* dequeue() 
    {
        Node *temp=NULL;
      if (isEmpty()) 
      {
          cout << "Queue is Empty" << endl;
          return NULL;
      } 
      else 
      {
        if(front==rear)
        {
          temp=front;
          front = NULL;
          rear = NULL;  
          return temp;
        }
        else
        {
          temp=front;
          front = front->next;  
          return temp;
        }
          
       }
    }
    int Front()
    {
        if(isEmpty())
        {
            cout<<"The queue is already empty";
            return 0;
        }
        else
        {
            return front->value;
        }
    }
    int count()
    {
        int cnt=0;
        Node* temp=front;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
    }
    void printQueue()
    {
        Node* temp=front;
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
    Queue q;
    for(int i=1;i<=5;i++)
    {
        q.enQueue(i);
    }
    q.printQueue();
    q.dequeue();
    q.printQueue();     
}