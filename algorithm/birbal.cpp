#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 1e5+10;
vector<int> G[lim];
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        for(int i=0;i<=n;++i)
            G[i].clear();
        int ans = INF;
        int left, right ;
        int sum = 0;
        G[sum].pb(0);
        for(int i=0;i<n;++i)
        {
            int a;
            scan(a);
            sum = sum+a;
            sum%=n;
            if( a%n == 0 && ans > 1)
            {
                ans = 1;
                left = i+1;
                right = i+1;
            }
            else
            {
                for(int a:G[sum])
                {
                    if( i-a+1 < ans)
                    {
                        ans = i-a+1;
                        left = a+1;
                        right = i+1;
                    }
                }
            }
            G[sum].pb(i);
        }
        cout<<left<<" "<<right<<endl;
    }
    return 0;
}


