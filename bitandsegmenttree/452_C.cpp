#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5;
vector<ll> first,second;
ll sum1,sum2 ;
int main()
{
    ll n;
    cin>>n;
    sum1 = 0ll;
    sum2 = 0ll;
    while( n > 0)
    {
        if( sum1 > sum2)
        {
            second.push_back(n);
            sum2 +=(1ll*n);
        }
        else
        {
            first.push_back(n);
            sum1+=(1ll*n);
        }
        n--;
    }
    cout<<abs(sum1-sum2)<<endl;
    cout<<first.size()<<" ";
    for(auto a:first)
        cout<<a<<" ";



    return 0;
}
