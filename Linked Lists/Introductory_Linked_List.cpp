#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int Value;
    Node* next;
};
void printList(Node *n)
{
    while(n!=0)
    {
        cout<<n->Value<<endl;
        n=n->next;//n->next, pointer to the next element;
    }
}
int main()
{
    Node* head=new Node();
    Node* second =new Node();
    Node* third=new Node();
    head->Value=1;
    head->next=second;
    second->Value=2;
    second->next=third;
    third->Value=3;
    third->next=NULL;
    printList(head);/*we just have to pass the head node, because head node contains the adrees of second node then second node contains the adress of third node and third node 
                    containing NULL*/

}