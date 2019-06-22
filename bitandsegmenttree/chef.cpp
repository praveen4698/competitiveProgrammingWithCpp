#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n;
        S(n);
        if( n%6 == 0)
            cout<<"Misha"<<endl;
        else
            cout<<"Chef"<<endl;
    }

    return 0;
}
