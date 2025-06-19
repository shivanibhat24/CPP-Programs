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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}