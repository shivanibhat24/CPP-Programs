#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    int revarr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int j=0;
    for(int i=(n-1);i>=0;i--)
    {
        revarr[j]=arr[i];
        j++;
    }
    for(int i=0;i<n;i++)
    cout<<revarr[i]<<" ";
    return 0;
}