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
void insertAtFront(Node** n,int newValue)
{
    //1. Prepareing new node
    Node* newnode=new Node();
    newnode->value=newValue;
    //2. Put the new node in front of current head
    newnode->next=*n;
    //3.Move head of the list to print to the new node
    *n=newnode;
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
    insertAtFront(&head,0);
    printList(head);
}