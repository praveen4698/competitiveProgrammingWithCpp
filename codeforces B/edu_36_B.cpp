#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main()
{
    int n,pos,l,r;
    scan2(n,pos);
    scan2(l,r);
    if( l == 1 && r == n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if( l == 1)
    {
        cout<<abs(pos-r)+1<<endl;
        return 0;
    }
    if( r == n)
    {
        cout<<abs(pos-l)+1<<endl;
        return 0;
    }

    if( pos <= l)
    {
        int ans = 0;
        if( l > 1)
            ans+=(pos-l+1);
        if( n > r)
        {
            ans+=(r-l+1);
        }
        cout<<ans<<endl;
        return 0;
    }
    if( pos >= r)
    {
        int ans = 0;
        if( r < n)
            ans = (pos-r+1);
        if( l > 1)
            ans+=(r-l+1);
        cout<<ans<<endl;
        return 0;
    }
    int ans1 = pos-l+1;
    if( n > r)
        ans1+=(r-l+1);
    int ans2 = r-pos+1;
    if( l > 1)
        ans2+=(r-l+1);
    cout<<min(ans1,ans2)<<endl;
    return 0;
}


