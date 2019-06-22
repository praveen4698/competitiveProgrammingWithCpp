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
vector<pair<int,int> > S;
map<pair<int, int> ,int> M;
map<pair<int,int> ,int> P;
vector<pair<int,int> > A,B;
bool compare(pair<int,int> l, pair<int,int> r){

    return (l.first < r.first) || ( l.first == r.first && l.second < r.second);
}
int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        S.clear();
        M.clear();
        P.clear();
        for(int i=0;i<n;++i){
            int a,b;
            S.push_back({a,b});
            P[{a,b}] = i;
        }
        sort(all(S),compare);
        A.clear();
        B.clear();
        
        for(int i)
    }
    return 0;
}
