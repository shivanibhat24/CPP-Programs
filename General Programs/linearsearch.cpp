#include<iostream>
using namespace std;
bool search(int arr[], int size, int key) 
{
    for( int i = 0; i<size; i++ )
    {
        if( arr[i] == key) 
        {
            return 1;
        }
    }
    return 0;
}
int main() {
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout <<" Enter the element to search for " << endl; 
    int key;
    cin >> key;
    bool found = search(arr, n, key);
    if( found ) {
        cout <<" Key is present "<< endl;
    }
    else{
        cout <<" Key is absent " << endl;
    }
    return 0;
}