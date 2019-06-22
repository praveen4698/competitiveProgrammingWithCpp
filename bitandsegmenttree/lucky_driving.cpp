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
const int lim = 1e4+10;
int dp[lim][10];
string S;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>S;
        int n = S.length();
        memset(dp,0,sizeof(dp));
       // dp[0][0] =1;
        int cont = 0;
        for(int i=1;i<=n;++i)
        {
            int a = (int)S[i-1]-'0';
            if( a == 0)
                cont++;
            dp[i][a%9]+=1;

            for(int j=0;j<9;j++)
            {
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
                dp[i][(j+a)%9]+=dp[i-1][j];
                dp[i][j]%=mod;
            }
          //  cout<<i<<" "<<dp[i][0]<<endl;

        }
        int ans = dp[n][0];
        int tt = powr(2,cont);
        tt--;
        if( tt < 0)
            tt+=mod;
        ans = ans - tt;

      //  ans--;
        if( ans < 0)
            ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
