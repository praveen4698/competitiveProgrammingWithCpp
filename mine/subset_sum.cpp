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
int dp[lim],ok[lim];
map<string,int> M;

int main()
{
    int d;
    string tmp,A;
    cin>>d;
    for(int i=0;i<d;++i)
    {
        cin>>tmp;
        sort(all(tmp));
        M[tmp] = 1;
    }
    int x,y,t;
    cin>>x>>y;
    cin>>t;
    while(t--)
    {
        int n = x*y;
        for(int i=0;i<=(1<<n);++i)
        {
            dp[i] = 0;
            ok[i] = 0;
        }
        A = "";
        for(int i=0;i<x;++i)
        {
            for(int j=0;j<y;++j)
            {
                char a;
                cin>>a;
                A+=a;
            }
        }
        for(int k=0;k<(1<<n);++k)
        {
            tmp = "";
            for(int i=0;i<n;++i)
            {
                if( k&(1<<i))
                    tmp+=A[i];
            }
            sort(all(tmp));
            ok[k] = M[tmp];
        }
        for(int k=0;k<(1<<n);++k)
        {
            for(int i=k;i>0;i=(i-1)&k)
            {
                if( ok[i] == 1 && dp[i^k] == 0)
                {
                    dp[k] = 1;
                    break;
                }
            }
        }
        int a = (1<<n)-1;
        if( dp[a] == 1)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}


