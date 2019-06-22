#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b)
{
	int x = 1 % mod;
	while(b)
    {
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
vector<int> factorize(int n)
{
	vector<int> vec;
	for(int i = 2; i * i <= n; i++)
    {
		if(n % i == 0)
		{
			while(n % i == 0) n /= i;
			vec.push_back(i);
		}
	}
	if(n != 1) vec.push_back(n);
	return vec;
}
const int lim = 6e5+10;
int cnt[lim],color[lim],level[lim],ans[lim];
vector<int> G[lim];
map<pair<int,int> ,int> dp;
void dfs(int v)
{
    int s;
    if( level[v] > 0 && level[v] < cnt[color[v]])
        s = dp[{color[v],level[v]-1}];
    else
        s = 0;
    //cout<<"s="<<s<<endl;
    for(int a:G[v])
        dfs(a);
    if( level[v] >= cnt[color[v]])
        return ;
    if( level[v] == 0)
        ans[v] = 1;
    else
        ans[v] = add(ans[v],dp[{color[v],level[v]-1}]-s+mod);
    //cout<<ans[v]<<endl;
    dp[{color[v],level[v]}] = add(ans[v],dp[{color[v],level[v]}]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        dp.clear();
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i=0;i<=n;++i)
        {
            G[i].clear();
            cnt[i] = 0;
            ans[i] = 0;
        }
        for(int i=1;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            G[a].push_back(i);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&color[i]);
            cnt[color[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&level[i]);
        }
        dfs(0);
        for(int i=0;i<n;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
