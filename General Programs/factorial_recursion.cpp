#include<bits/stdc++.h>
using namespace std;

int fact(int num)
{
    if(num==0)
      return 1;
    return fact(num-1)*num;
}

int main()
{
    int n;
    cout<<"Enter the number whose factorial you want to see:"<<endl;
    cin>>n;
    int ans= fact(n);
    cout<<"The factorial of "<<n<<" natural numbers is: "<<ans<<endl;
    return 0;
}
