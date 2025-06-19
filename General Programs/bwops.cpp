#include<iostream>
using namespace std;


int main() {

    int a,b;
    cout<<"Enter the two numbers:"<<endl;
    cin>>a>>b;

    cout<<" a&b " << (a&b) << endl;
    cout<<" a|b " << (a|b) << endl;
    cout<<" ~a " << ~a << endl;
    cout<<" a^b " << (a^b) << endl;

    cout<< (a>>b)<<endl;
    cout<< (a<<b) <<endl;

}