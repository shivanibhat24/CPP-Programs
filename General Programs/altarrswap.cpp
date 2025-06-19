#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=1;i<n;i=i+2)
    swap(arr[i],arr[i-1]);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}