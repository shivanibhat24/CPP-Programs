#include<bits/stdc++.h>
using namespace std;

int sum(int num)
{
    if(num==0)
      return 0;
    return sum(num-1)+num;
}

int main()
{
    int n;
    cout<<"Enter the last natural number whose sum you want to see:"<<endl;
    cin>>n;
    int ans= sum(n);
    cout<<"The sum of "<<n<<" natural numbers is: "<<ans<<endl;
    return 0;
}