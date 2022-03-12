#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
};
void printList(Node* n)
{
    while(n!=0)
    {
        cout<<n->value<<endl;
        n=n->next;
    }
}
void insertAfter(Node* previous, int newValue)
{
    //1.Check whether the previous node is empty or not
    if(previous==NULL)
    {
        cout<<"Previous node can not be null";
        return;
    }
    //2.Create a newNode
    Node* newNode=new Node();
    newNode->value=newValue;
    //3. Insert new node after previous element
    newNode->next=previous->next;
    previous->next=newNode;
}
int main()
{
    Node* head=new Node();
    Node* second=new Node();
    Node* third =new Node();
    head->value=1;
    head->next=second;
    second->value=2;
    second->next=third;
    third->value=3;
    third->next=NULL;
    insertAfter(head,-1);
    insertAfter(second,-2);
    insertAfter(third,-3);
    printList(head);
}