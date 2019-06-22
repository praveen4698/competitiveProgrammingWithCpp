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

string S;
vector<pair<int,int> > edge;
vector<int> G[100];
int a[101];
vector<int> B;
int dp[101][101][101];
bool DFS(int ver,int par,int zero,int one,int two,int myvalue){

    if( dp[ver][zero][one] == 1 || dp[ver][zero][one] == 2  ){
            return (dp[ver][zero][one] == 2);
    }

    for(int i:G[ver]){

        if( i == par){
            continue;
        }

        if( myvalue == 0){
            bool t1 = false;
            bool t2 = false;
            if( zero > 0){
                t1 = DFS(i,ver,zero-1,one,two,0);
            }
            if( one > 0){
                t2 = DFS(i,ver,zero,one-1,two,1);
            }
            if( t2 == false && t1 == false){
                dp[ver][zero][one] = 1;
                return false;
            }
        }
        if( myvalue == 1){
            bool t1 = false;
            bool t2 = false;
            bool t3 = false;
            if( zero > 0){
                t1 = DFS(i,ver,zero-1,one,two,0);
            }
            if( one > 0){
                t2 = DFS(i,ver,zero,one-1,two,1);
            }
            if( two > 0){
                t3 = DFS(i,ver,zero,one,two-1,2);
            }
            if( t2 == false && t1 == false && t3 == false){
                dp[ver][zero][one] = 1;
                return false;
            }
        }
        if( myvalue == 2){
            bool t1 = false;
            bool t2 = false;
            if( one > 0){
                t1 = DFS(i,ver,zero,one-1,two,1);
            }
            if( two > 0){
                t2 = DFS(i,ver,zero,one,two-1,2);
            }
            if( t2 == false && t1 == false){
                dp[ver][zero][one] = 1;
                return false;
            }
        }
    }

    dp[ver][zero][one] == 2;
    return true;

}
int main()
{
    int t;
    scan(t);
    while(t--){
        edge.clear();
        B.clear();
        int zero=0,one = 0,two=0;
        int n;
        scan(n);
        B.resize(n);
        for(int i=1;i<=n;++i){
            scan(B[i]);
            a[i] = 0;
            if( B[i] == 0)
                zero++;
            else if( B[i] == 1)
                one++;
            else
                two++;
        }
        for(int i=0;i<n+1;++i){
            for(int j=0;j<=zero;++j){
                for(int k=0;k<=one;++k){
                    dp[i][j][k] = 0;
                }
            }
        }

        for(int i=0;i<n-1;++i){
            int a,b;
            scan2(a,b);
            edge.push_back(make_pair(a,b));
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans = 2;
        if( zero == n || one == n || two == n)
            ans = 0;
        else {
        for(int i=1;i<2;++i){

            if( zero > 0){
                if( DFS(1,-1,zero-1,one,two,0))
                    ans = min(ans,i);
            }
            else if( one > 0){
                
                if( DFS(1,-1,zero,one-1,two,0)){
                    ans = min(ans,i);
                }
            }
            else{
                if( DFS(1,-1,zero,one,two-1,0)){
                    ans = min(ans,i);
                }
            }
        }}
        cout<<ans<<endl;
    }
    return 0;
}
