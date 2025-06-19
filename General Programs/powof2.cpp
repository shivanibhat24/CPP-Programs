#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    int count=0;
    int ans = 1;
    for(int i = 0; i <= 30; i++) {
        if(ans == n)
        {
            count++;
        }
        if(ans < INT_MAX/2)
        ans = ans * 2;   
            
    }
    if(count==0)
    cout<<"False"<<endl;
    else
    cout<<"True"<<endl;
    return 0;
}