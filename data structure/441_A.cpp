#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        if( n == 1)
        {
            cout<<0;
            return 0;
        }

        cout<<min(min((n-1)*a,(n-1)*b),min(a+(n-2)*c,b+(n-2)*c));
        return 0;
    }

