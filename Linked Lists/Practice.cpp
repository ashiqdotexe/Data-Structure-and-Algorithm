#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
};
void printList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }
}
void insertAtFront(Node** head,int newValue)
{
    Node* newnode=new Node();
    newnode->value=newValue;
    newnode->next=*head;
    *head=newnode;
}
void inserAtEnd(Node** head,int newValue)
{
    Node* newnode=new Node();
    newnode->value=newValue;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    Node* last=*head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
}
int main()
{
    Node* head=new Node();
    Node* second =new Node();
    Node* third =new Node();
    head->value=1;
    head->next=second;
    second->value=2;
    second->next=third;
    third->value=3;
    third->next=NULL;
    insertAtFront(&head,0);
    inserAtEnd(&head,4);
    printList(head);
}