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

const int lim = 1e6+10;
int cont[lim];
int done[lim];
set<int> A;
int main()
{
    int t;
    scan(t);
    memset(cont,0,sizeof(cont));
    memset(done,0,sizeof(done));
    while(t--){
        int n;
        scan(n);
        A.clear();
        for(int i=0;i<n;++i){
            int a;
            scan(a);
            A.insert(a);
            cont[a]++;
        }
        ll ans = 0;
        for(int a:A){
            for(int i=1;i<=cont[a];++i){
                if( cont[i] >= a){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        for(int a: A){
            cont[a] = 0;
        }


    }
    return 0;
}
