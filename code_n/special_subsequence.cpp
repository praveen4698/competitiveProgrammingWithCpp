#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 21;
const int mask = 1<<21;
ll A[lim];
int main()
{
    int t;
    scan(t);
    while(t--){
        ll n,k,m;
        scanf("%lld %lld %lld",&n,&m,&k);
        ll ans = 0ll;
        int ret = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        for(int i=0;i<(1<<n);++i){
            ll temp = 0;
            for(int j=0;j<n;++j){
                if( i&(1<<j) ){
                    temp = (temp+ A[j]*1ll*A[j])%m;
                }
            }
            if( temp == k)
                ret++;
        }
        cout<<ret<<endl;
    }

    return 0;
}

 