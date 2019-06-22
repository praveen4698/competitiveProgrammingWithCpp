#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5 + 10;
    long long int fact[lim];
    vector<int> G[lim];
    void facti()
    {
        fact[0] = 1LL*1;
        for(int i=1;i<lim;++i)
            fact[i] = (1LL*fact[i-1]*i)%mod;
    }
    long long int DFS(int x,int par = -1)
    {
        int cont =0;
        long long ans = 1;
        for(int i=0;i<G[x].size();i++)
        {
            if( G[x][i] != par)
            {
                cont++;
                ans = (ans*DFS(G[x][i],x))%mod;
            }
        }
        ans = (ans*fact[cont])%mod;
        return ans;


    }
    int main()
    {
        int t;
        scanf("%d",&t);
        facti();
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n+1;i++)
                G[i].clear();
            for(int i=1;i<n;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
            int a;
            scanf("%d",&a);
            printf("%lld\n",DFS(a));
        }
        return 0;
    }
