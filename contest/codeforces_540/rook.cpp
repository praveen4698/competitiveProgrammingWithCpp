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
const int lim = 1e6+10;
int row[lim],col[lim];
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,k;
        scan2(n,k);
        for(int i=0;i<=n;++i){
            row[i] = 0;
            col[i]  = 0;
        }
        for(int i=0;i<k;++i){
            int a,b;
            scan2(a,b);
            row[a] = 1;
            col[b] = 1;

        }
        vector<int> A,B;
        for(int i=1;i<=n;++i){
            if( row[i] == 0)
                A.push_back(i);
            if( col[i] == 0)
                B.push_back(i);
        }
        assert(A.size() == B.size());
        cout<<A.size()<<" ";
        for(int i=0;i<A.size(); i++){
            cout<<A[i]<<" "<<B[i]<<
        }
    }
    return 0;
}
