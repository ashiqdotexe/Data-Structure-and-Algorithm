//I am still working on sorting function.

#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    int key;
    Node* next;
    Node* previous;
    Node()
    {
        data=0;
        key=0;
        next=NULL;
        previous=NULL;
    }
    Node(int key,int data)
    {
        this->key=key;
        this->data=data;
    }                                                                 
};
class DoublyLikedList
{
    public:
    Node* head;
    DoublyLikedList()
    {
        head=NULL;
    }
    DoublyLikedList(Node* newNode)
    {
        head=newNode;
    }
   Node * nodeExist(int k) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }
    void append(Node* newNode)
    {
        if(nodeExist(newNode->key)!=NULL)
        {
            cout<<"The node is already exist with the same key value";
        }
        else
        {
            if(head==NULL)
            {
                head=newNode;
                cout<<"Node appended"<<endl;
            }
            else
            {
                Node* ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=newNode;
                newNode->previous=ptr;
                cout<<"Node appended"<<endl;
            }
        }
    }
    void prepend(Node *newNode)
    {
        if(nodeExist(newNode->key)!=NULL)
        {
            cout<<"The node is already exist with the same key value";
        }
        else
        {
            if(head==NULL)
            {
                head=newNode;
            }
            else
            {
                newNode->next=head;
                head->previous=newNode;
                head=newNode;
                newNode->previous=NULL;
            }
        }
    }
    void insertAfter(int k,Node* newNode)
    {
        Node* ptr=nodeExist(k);
        if(ptr==NULL) cout<<"There is no such node present in the list";
        else
        {
            if(nodeExist(newNode->key)!=NULL)
            {
                cout<<"The node is already exist with the same key value";
            }
            else
            {
                if(head==NULL)
                {
                    head=newNode;
                }
                else
                {
                    Node* temp=ptr->next;
                    if(temp==NULL)
                    {
                        ptr->next=newNode;
                        newNode->previous=ptr;
                        temp->next=NULL;
                    }
                    else
                    {
                        temp->previous=newNode;
                        newNode->next=temp;
                        ptr->next=newNode;
                        newNode->previous=ptr;
                    }
                }
            }
        }
    }
    void deleteNode(int k)
    {
        Node* ptr=nodeExist(k);
        if(ptr==NULL)
        {
            cout<<"There is no such node in the list with such key value";
        }
        else
        {
            if(head==NULL)
            {
                cout<<"The list is already empty";
            }
            else
            {
                if(head->key==k)
                {
                    head=head->next;
                    cout<<"Node deleted";
                }
                else
                {
                    Node* nextNode=ptr->next;
                    Node * prevNode=ptr->previous;
                    if(nextNode==NULL)
                    {
                        prevNode->next=NULL;
                        cout<<"Node deleted";
                    }
                    else{
                    nextNode->previous=prevNode;
                    prevNode->next=nextNode;
                    cout<<"Node deleted"<<endl;
                    }
                }
            }
        }
    }
    void updateNode(int k,int d)
    {   
        Node* ptr=nodeExist(k);
        if(ptr==NULL)
        {
            cout<<"There is no such node with the key value"<<endl;
        }
        else
        {
            if(ptr->key==k)
            {
                ptr->data=d;
                cout<<"Node updated"<<endl;
            }
            else
            {
                cout<<"There is no such node in the list with key value"<<endl;
            }
        }
    }
    void printList()
    {
        if(head==NULL)
        {
            cout<<"The node is empty";
        }
        else
        {
            Node* temp=head;
            while ((temp!=NULL))
            {
                cout<<"("<<temp->key<<","<<temp->data<<") -->>";
                temp=temp->next;
            }
        }
    }
    void retrieveNode(int k)
  {
    Node* ptr=nodeExist(k);
    if(ptr==NULL)
    {
      cout<<"There is no such node with the same key value "<<k<<". Please enter a new key value"<<endl;
    }
    else
    {
      if(head==NULL)
      {
        cout<<"The list is empty";
      }
      else
      {
        if(head->key==k)
        {
          cout<<"("<<head->key<<","<<head->data<<")";
        }
        else
        {
          cout<<"("<<ptr->key<<","<<ptr->data<<")";
        }
      }
    }
  }
  void sorting()
  {
    if(head==NULL)
    {
      cout<<"The list is already empty";
    }
    else{
      Node* nextNode=head->next;
      Node* prevNode=head->previous;
      if((head->key)>(nextNode->key))
      {
        head->next=nextNode->next;
        nextNode->next->previous=head;
        nextNode->next=head;
        head->previous=nextNode;
        head=nextNode;
        cout<<"Sorted"<<endl;
      }
      else
      {
        while(nextNode!=NULL)
        {
          if((nextNode->key)>(nextNode->next->key))
          {
            nextNode->previous->next=nextNode->next;
            nextNode->next->previous=nextNode->previous;
            nextNode->next=NULL;
            cout<<"Sorted"<<endl;
          }
          else
          {
            nextNode=nextNode->next;
          }
        }
      }
    }
  }
};
int main() {

  DoublyLikedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout<<"7.Retrieve a particular item"<<endl;
    cout<<"8.Sorting"<<endl;
    cout << "9. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.append(n1);
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prepend(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNode(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      cout<<"Enter the of the item that you want to retrieve: "<<endl;
      cin>>k1;
      s.retrieveNode(k1);
      break; 
    case 8:
      
      s.sorting();
      break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
