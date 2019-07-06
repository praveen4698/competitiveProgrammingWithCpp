#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1000000000
#define linf 100000000000000000LL
typedef pair< ll , ll > ii;
typedef pair< ll ,pair< ll , ll > > iii;

map< ll , ll > mp;
ll a[2005];
ll b[2005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,j,temp,ct;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=1;
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        mp[b[i]]=1;
    }
    ct=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            temp=a[i]^b[j];
            if( mp[temp]==1 )
                ct++;
        }
    }
    if( !(ct&1) )
        cout<<"Karen\n";
    else
        cout<<"Koyomi\n";

    return 0;
}
