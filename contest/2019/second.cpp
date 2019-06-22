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

set<int> S;
set<int> t;
int A[20];
int main()
{
    int n;
    S.insert(0);
    scan(n);
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        t.clear();
        for(int s:S){
            t.insert(s+a);
            t.insert(s-a);
            
        }
        S.clear();
        for(int s:t){
            // cout<<"int "<<s<<endl;
            S.insert(s);
        }
    }
    for(int i:S){
        // cout<<i<<endl;
        if( abs(i)%360 == 0){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
