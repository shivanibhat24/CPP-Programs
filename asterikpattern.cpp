#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int columns;
    cout<<"Enter the number of columns:"<<endl;
    cin>>columns;
    for(int i=1;i<=columns;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<'*';
        }
        cout<<""<<endl;
    }
    return 0;
}