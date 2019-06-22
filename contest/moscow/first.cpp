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
const int lim = 1e5+10;
vector<int> A;
int ans[lim]; 
int main()
{
    int t;
    scan(t);
    while(t--){

        int n,k;
        scan2(n,k);
        for(int i=0;i<=n;++i)  
            ans[i] = -1;
        if( n > 1 && k == 1){
            int a;
            scan(a);
            cout<<"NO"<<endl;
            continue;
        }
        A.clear();
        A.resize(k);
        for(int i=0;i<k;++i){
            scan(A[i]);
        }
        int tt = n-k-A[0]+2;
        for(int i:A){
            ans[i]= tt++;
        }
        int cont = n;
        for(int i=1;i<A[0];++i){
            ans[i] = cont;
            cont--;
        }
        tt = n-k-A[0]+1;
        for(int i=1;i<=n;++i){
            if( ans[i] == -1){
                ans[i] = tt;
                tt--;
            }
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;++i){
            printf("%d ",ans[i]);
        }
        cout<<endl;
    }
    return 0;
}
