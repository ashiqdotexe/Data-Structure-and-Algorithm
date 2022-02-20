#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    int **table=new int*[row];
    for(int i=0;i<row;i++)
    {
        table[i]=new int[col];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"Please enter ["<<i<<"]"<<"["<<j<<"]= ";
            cin>>table[i][j];
        }
    }    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++){

        cout<<"["<<i<<"]"<<"["<<j<<"]= "<<table[i][j];
        cout<<endl;
    }
    }
    cout<<endl;
    for(int i=0;i<row;i++)
    {
        delete[] table[i];
    }
    delete[] table;
    table=NULL;
}