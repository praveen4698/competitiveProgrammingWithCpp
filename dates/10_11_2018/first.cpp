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


int main()
{   
    ll ans[7];
    for(int i=0;i<7;++i)
        ans[i] = 1ll*INF;
    int n;
    scan(n);
    for(int i=0;i<n;++i){
        ll a;
        string S;
        cin>>a>>S;
        if( S.length() == 1){
            if( S[0] == 'A'){
                ans[0] = min(ans[0],a);
                ans[6] = min(ans[6], ans[0]+ans[5]);
            }
            else if( S[0] == 'B'){
                ans[1] = min(ans[1],a);
                ans[6] = min(ans[6], ans[1]+ans[4]);
            }
            else{
                ans[2] = min(ans[2],a);
                ans[6] = min(ans[6], ans[2]+ans[3]);
            }
        }
        else if( S.length() == 2){
            sort(all(S));
            if( S[0] == 'A' && S[1] == 'B'){
                ans[3] = min(ans[3],a);
                ans[6] = min(ans[6], ans[3]+ans[2]);
                ans[6] = min(ans[6], ans[3]+ans[4]);
                ans[6] = min(ans[6], ans[3]+ans[5]);
            }
            else if(S[0] == 'A' && S[1] == 'C'){
                ans[4] = min(ans[4] ,a);
                ans[6] = min(ans[6], ans[4]+ans[1]);
                ans[6] = min(ans[6], ans[4]+ans[3]);
                ans[6] = min(ans[6], ans[4]+ans[5]);
            }
            else{
                ans[5] = min(ans[5],a);
                ans[6] = min(ans[6], ans[5]+ans[0]);
                ans[6] = min(ans[6], ans[5]+ans[4]);
                ans[6] = min(ans[6], ans[5]+ans[3]);
            }
        }
        else{
            sort(all(S));
            ans[6] = min(ans[6],a);
        }
        ans[6] = min(ans[6],ans[0]+ans[1]+ans[2]);

    } 
    if( ans[6] == INF){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans[6]<<endl;
    return 0;
}
