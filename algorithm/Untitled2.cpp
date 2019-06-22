#include<iostream>
using namespace std;
//#include<conio.h>
int main()
{
    int n,i,f=1;
    cout<<"enter a number \n";
    cin>>n;
    for(i=n;i>=1;i--)
    {
        f=f*i;
    }
    cout<<"factorial="<<f;
    return 0;
}
