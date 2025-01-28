#include<bits/stdc++.h>
using namespace std;

void TOH(int n,int a,int b, int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        cout<<"("<<a<<","<<c<<")"<<endl;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    int n,a,b,c;
    cout<<"Enter the number of disks: ";
    cin>>n;
    cout<<"Enter the source rod: ";
    cin>>a;
    cout<<"Enter the auxiliary rod: ";
    cin>>b;
    cout <<"Enter the destination rod: ";
    cin>>c;
    TOH(n,a,b,c);
    return 0;
}
