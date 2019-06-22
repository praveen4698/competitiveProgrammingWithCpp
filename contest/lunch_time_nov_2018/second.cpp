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

vector<int> A;
vector<int> B;
vector<pair<int,int> > q;
int ans = 0;
void solve(vector<int> tt,vector<pair<int,int> > q){
    int n = q.size();
    if( n == 0){
        int x = tt.size();
        int flag = 0;
        for(int i=0;i<x;++i){
            if( tt[i] != B[i]){
                flag = 1;
            }
        }
        if( flag == 0)
            ans++;
        return ;
    }

    vector<pair<int,int> > q2;
    for(int i=0;i<q.size();++i){
        q2.clear();
        for(int j=0;j<q.size();++j){
            if( i!= j){
                q2.push_back(q[i]);
            }
        }
        int a = q[i].first;
        int b = q[i].second;
        reverse(A.begin()+a-1,A.begin()+b);
        solve(A,q2);
        reverse(A.begin()+a-1,A.begin()+b);
    }
}
int main()
{
    int t;
    scan(t);
    while(t--){
        A.clear();
        B.clear();
        q.clear();
        int n,m;
        scan2(n,m);
        for(int i=0;i<n;++i){
            int a;
            scan(a);
            A.push_back(a);
            B.push_back(a);
        }
        for(int i=0;i<m;++i){
            int a,b;
            scan2(a,b);
            q.push_back(make_pair(a,b));
            reverse(B.begin()+a-1,B.begin()+b);
        }
       
        ans = 0;
        int dem = 1;
        for(int i=1;i<=m;++i){
            dem*=i;
        }
        solve(A,q);
        int gcd = __gcd(ans,dem);
        // cout<<ans<<" "<<dem<<endl;
        printf("%d/%d\n",ans/gcd,dem/gcd);
    }
    return 0;
}
