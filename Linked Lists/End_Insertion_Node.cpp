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
void insertAtEnd(Node** head,int newValue)
{
    //1. Prepareing new node
    Node* newnode=new Node();
    newnode->value=newValue;
    newnode->next=NULL;
    //2. Check wheater list is empty or not
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    //3.Find the last node of the list if 2 is false
    Node* last=*head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    //4. Insert new Node after last node
    last->next=newnode;
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
    insertAtEnd(&head,4);
    printList(head);
}