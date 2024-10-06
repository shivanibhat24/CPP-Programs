#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n value:"<<endl;
    cin>>n;
    int m = n;
    int ans;
    int mask = 0;
    if(n == 0)
    int ans=1;
    while( m!=0) 
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    ans = (~n) & mask;
    cout<<ans<<endl;
    return 0;
}
        