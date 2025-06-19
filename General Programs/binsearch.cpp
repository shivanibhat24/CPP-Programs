#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size-1;
    sort(arr,arr+size);
    int mid = start + (end-start)/2;
    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}

int main() 
{ 
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout <<" Enter the element to search for " << endl; 
    int key;
    cin >> key;
    int found = binarySearch(arr, n, key);
    if( found!=-1 ) {
        cout <<" Key is present at position:"<<(found+1)<< endl;
    }
    else{
        cout <<" Key is absent " << endl;
    }
    return 0;
    return 0;
}
int findPeak(int arr[], int n) {
    int s =0, e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}