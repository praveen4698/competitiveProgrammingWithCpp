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
const int lim = 1e5+10;
int A[11][lim];
int location[11][lim];
int main()
{
    int n;
    scan(n);
    int m;
    scan(m);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scan(A[i][j]);
            location[i][A[i][j]] = j;
        }
    }
    int c = 1;
    int start = 0;
    ll ans = 0;
    for(int i=1;i<n;++i){
        bool flag = true;
        for(int j=1;j<m;++j){

            int t = location[j][A[0][start]];
            // cout<<i<<" "<<t<<endl;
            if( t+c >= n){
                flag = false;
                break;
            }
            if( A[0][start+c] != A[j][t+c]){
                flag = false;
                break;
            }
        }
        // cout<<c<<endl;
        if(flag == false){
            ans = ans + ((c)*1ll*(c+1))/2;
            c = 1;
            start = i;
        }
        if( flag == true && i == n-1){
            c++;
            ans = ans + ((c)*1ll*(c+1))/2;
        }
        if(flag == true ){
            c++;
        }
        if( flag == false && i == n-1){
            ans = ans +1;
        }

    }
    cout<<ans<<endl;
    return 0;
}
