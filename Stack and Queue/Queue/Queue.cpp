#include<bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
    int front;
    int rear;
    int arr[5];
    public:
    Queue();
    bool isFull();
    bool isEmpty();
    void enQueue(T);
    int deQueue();
    void print();
    int count();
};
template <class T>
Queue<T>::Queue()
{
    front = -1;
    rear = -1;
    for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
}
template <class T>
bool Queue<T>::isFull()
{
    if (rear == 4)
      return true;
    else
      return false;
}
template <class T>
bool Queue<T>::isEmpty()
{
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
}
template <class T>
void Queue<T>::enQueue(T val)
{
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;
    } else {
      rear++;
      arr[rear] = val;
}
}
template <class T>
int Queue<T>::deQueue()
{
    int x;
    if(isEmpty())
    {
        cout<<"Queue is already empty"<<endl;
        return 0;
    }
    else if(rear==front)
    {
        x=arr[front];
        arr[front]=0;
        rear=-1;
        front=-1;
        return x;
    }
    else
    {
        x=arr[front];
        arr[front]=0;
        front++;
        return x;
    }
}
template <class T>
int Queue<T>::count()
{
    return (rear-front+1);
}
template <class T>
void Queue<T>::print()
{
    cout<<"Printing all elements:>>"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<", ";
    }
}
int main() {
  Queue <int> q1;
  int value, option;

  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      cin >> value;
      q1.enQueue(value);
      break;
    case 2:
      cout << "Dequeue Operation \nDequeued Value : " << q1.deQueue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      q1.print();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}