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
int u[lim],r[lim];
int x,y,n;
string s;
bool check(int len){

    for(int i=1;i+len-1<=n;++i){
        
        int up = u[n] + u[i-1] - u[i+len-1];
        int ri = r[n] + r[i-1] - r[i+len-1];
        int upr = abs(x-up);
        int rir = abs(y-ri);
        if( upr+rir <= len && ((len-(upr+rir))%2 == 0))
            return true;
    }
    return false;
}

int main()
{
    memset(u,0,sizeof(u));
    memset(r,0,sizeof(r));
    // int n;
    scan(n);
    cin>>s;
    for(int i=0;i<n;++i){
        
        u[i+1] = u[i];
        r[i+1] = r[i];
        if( s[i] == 'R')
            r[i+1]++;
        if( s[i] == 'L')
            r[i+1]--;
        if( s[i] == 'U')
            u[i+1]++;
        if( s[i] == 'D')
            u[i+1]--;
    }
    scan2(y,x);
    if( u[n] == x && r[n] == y){
        printf("0\n");
        return 0;
    }
    int l = 1;
    int r = n;
    while(l<r){
        int mid = (l+r)/2;
        // cout<<check(mid)<<" "<<mid<<endl;
        if( check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    if( check(l))
        print(l);
    else
        printf("-1\n");
    return 0;
}
