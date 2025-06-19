#include<bits/stdc++.h>
using namespace std;

// We perform Taylor's Series using Horner's Rule

double e(int x,int n)
{
    static double s;
    if(n==0)
      return s;
    s=1+x*s/n;
}

int main()
{
    int x,n;
    cout<<"Enter the values of x and n:"<<endl;
    cin>>x>>n;
    int ans=e(x,n);
    cout<<"The Taylor's Series Expansion is: "<<ans<<endl;
    return 0;
}