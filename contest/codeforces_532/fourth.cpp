#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;
const ll mod = 998244353;
const int lim = 1001;
int dp[lim][lim];
vector<pair<int,int> >  rowleft[10],rowright[10],colup[10],coldown[10];
string S[lim];
string tt = "0123456789";
int check(int i, int j){
    for(int k=0;k<10;++k){
        if( S[i][j] == tt[k])
            return k;
    }
    return -1;
}
int main()
{   
    int n,m,p;
    scan3(n,m,p);
    memset(dp,0,sizeof(dp));
    int s[10];
    for(int i=1;i<=p;++i)
        scan(s[i]);
    for(int i=0;i<n;++i){
        cin>>S[i];
        for(int j=0;j<m;++j){
            if( check(i,j) > 0){
                dp[i][j] = check(i,j);
                col
            }
            else if( dp[i][j] == '#')
                dp[i][j] = -1;
            
        }
    }
    
    return 0;
}
