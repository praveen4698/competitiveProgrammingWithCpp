#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long long int n,r1,r2,r3;
            long long int An;
            cin>>n;
            n--;
            An = (n/3)*3;
            r1 = An*(An+3);
            r1 = r1/6;
            An = (n/5)*5;
            r2 = An*(An+5);
            r2 = r2/10;
            An = (n/15)*15;
            r3 = (An)*(An+15);
            r3 = r3/30;
            cout<<r1+r2-r3<<"\n";

        }
        return 0;
    }
