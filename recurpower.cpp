#include<bits/stdc++.h>
using namespace std;

int pow(int m, int n)
{
    if(n==0)
      return 1;
    return pow(m,n-1)*m;
}

int main()
{
    int m,n;
    cout<<"Enter the base:"<<endl;
    cin>>m;
    cout<<"Enter the exponent:"<<endl;
    cin>>n;
    int ans= pow(m,n);
    cout<<"The power is: "<<ans<<endl;
    return 0;
}
