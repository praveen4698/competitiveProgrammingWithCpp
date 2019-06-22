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
const int lim = 2e5+10;
const int logn = 20;
//int lps[lim];
vector<int> lps_array(string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n);
    for (int i = 1; i < n; ++i)
    {
		int j = lps[i - 1];
		while (j > 0 && pattern[i] != pattern[j])
            j = lps[j - 1];
		lps[i] = j + (pattern[i] == pattern[j]);
	}
	return lps;
}
int dp[lim][logn],cont[lim];
string S;
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,q;
        scan2(n,q);
        cin>>S;
        vector<int> lps = lps_array(S);
       // for(int i=0;i<n;++i)
        //    cout<<i<<" "<<lps[i]<<endl;
        for(int i=0;i<n;++i)
        {
            cont[i+1] = cont[lps[i]] + 1;
            dp[i+1][0] = lps[i];
            for(int j=1;j<logn;++j)
                dp[i+1][j] = dp[dp[i+1][j-1]][j-1];
        }
        while(q--)
        {
            int p,k;
            scan2(p,k);
            if( cont[p] < k)
            {
                printf("-1\n");
                continue;
            }
            k = cont[p]-k;
            for(int i=logn-1;i>=0;--i)
                if( k&(1<<i))
                    p = dp[p][i];
            cout<<p<<endl;
        }
        for(int i=0;i<n;++i)
        {
            memset(dp[i],0,sizeof(dp[i]));
            cont[i] = 0;
        }
    }
    return 0;
}
