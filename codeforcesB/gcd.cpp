#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            ll n;
            cin>>n;
            if( n ==1)
            {
                cout<<"1"<<"\n";
                continue;
            }
            ll prev = 2;
            for(int i=3;i<n+1;++i)
            {
                prev = prev*i/__gcd(prev,1ll*i);

            }
            cout<<prev<<"\n";
        }
        return 0;
    }
