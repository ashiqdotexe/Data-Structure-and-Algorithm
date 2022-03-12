#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED
#include<iostream>
using namespace std;
const int max_items = 5;
template<class T>
class UnsortedList
{
private:
    T data[max_items];
    int length;
    int currentPos;
public:
    UnsortedList();
    bool isEmpty();
    bool isFull();
    void makeEMpty();
    void Insert(T);
    void Delete(T);
    int isLength();
    void getNextItem(T&);
    void resetList();
    void retriveValue(T&, bool&);
};
#endif//UNSORTED_H_INCLUDED
 
template<class T>
UnsortedList<T>::UnsortedList()
{
    length = 0;
    currentPos = -1;
}
 
template<class T>
bool UnsortedList<T>::isEmpty()
{
    return length == 0;
}
 
template<class T>
bool UnsortedList<T>::isFull()
{
    return length == max_items;
}
 
template<class T>
void UnsortedList<T>::makeEMpty()
{
    length = 0;
}
 
template<class T>
void UnsortedList<T>::Insert(T item)
{
    data[length] = item;
    length++;
}
 
template<class T>
void UnsortedList<T>::Delete(T item)
{
    int location = 0;
    for(int i=0;i<length;i++)
    {
        if(data[i] == item)
        {
            location = i;
            break;
        }
    }
    data[location] = data[length-1];
    length--;
}
 
 
template<class T>
int UnsortedList<T>::isLength()
{
    return length;
}
 
template<class T>
void UnsortedList<T>::getNextItem(T& item)
{
    currentPos++;
    item = data[currentPos];
}
template<class T>
void UnsortedList<T>::resetList()
{
    currentPos = -1;
}
template<class T>
void UnsortedList<T>::retriveValue(T& item, bool& isFound)
{
    for(int i=0;i<length;i++)
    {
        if(data[i] == item)
        {
            isFound = true;
            return;
        }
    }
}
void PrintList(UnsortedList<int> u)
{
    int temp;
    for(int i = 0 ; i<u.isLength();i++)
    {
        u.getNextItem(temp);
        cout<<temp<<endl;
    }
    u.resetList();
}
void RetriveItem(UnsortedList<int> u, int search)
{
 
}
int main()
{
    UnsortedList<int> u1;
 
    u1.Insert(4);
    u1.Insert(5);
    u1.Insert(41);
    u1.Insert(15);
    PrintList(u1);
    int search;
    cin>>search;
    bool found = false;
    u1.retriveValue(search,found);
    if(found)
    {
        cout<<search<<" is in the list"<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
 
 
 
    return 0;
 
 
}