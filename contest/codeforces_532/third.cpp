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
const int lim = 1e6;
ll dp[lim][5];
ll cont[4];
int main()
{
    ll n,l,r;
    cin>>n>>l>>r;
    ll t = (r-l+1)/3ll;
    cont[0] = t;
    cont[1] = t;
    cont[2] = t;
    for(ll i=l+(t)*3;i<=r;++i){
        cont[i%3ll]++;
    }
    dp[0][0] = cont[0];
    dp[0][1] = cont[1];
    dp[0][2] = cont[2];
    for(int k=1;k<n;++k){

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                dp[k][(i+j)%3] = dp[k][(i+j)%3] + (dp[k-1][i]*cont[j])%MOD;
                dp[k][(i+j)%3] = dp[k][(i+j)%3]%MOD;
            }
        }
    }
    cout<<dp[n-1][0]<<endl;
    return 0;
}

vector<int> solution(vector<int> &T){
    int n = T.size();
    vector<int> dist(n);
    vector<int> G[100001];
    for(int i=0;i<n;++i)
        dist[i] = 1000000;
    int root = -1;
    for(int i=0;i<n;++i){
        if( T[i] == i){
            root = i;
        }
        else{
            G[T[i]].push_back(i);
            G[i].push_back(T[i]);
        }
    }
    queue<int> Q;
    Q.push(root);
    dist[root] = 0;
    while(!Q.empty()){
        int p = Q.front();
        Q.pop();
        for(int a:G[p]){
            if( dist[a] > dist[p]+1){
                dist[a] = dist[p]+1;
                Q.push(a);
            }
        }
    }
    vector<int> ans(n-1);
    for(int i=0;i<n-1;++i)
        ans[i] = 0;
    for(int i=0;i<n;++i){
        if( i == root)
            continue;
        ans[dist[i]]++;
    }
    return ans;
}
int check(char a){
    return a-'0';
}
int convert(string S){
    int x = 60*(check(S[0])*10 + check(S[1])) + (check(S[3])*10 + check(S[4])  );
    return x;
}
int solution(string E,string L){
    int diff = convert(L) - convert(E);
    int x = diff/60 + (diff%60 > 0);
    x--;
    return 2 + 3 + x*4;
}