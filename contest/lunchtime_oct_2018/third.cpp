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

ll ans ;
int A[100];
int n,s;
void solve(int i,int sum){

    // printf(" sum %d %d %d %d \n",i,n,sum,s);
    if( sum > s){
        return ;
    }
    if( i > n)
        return ;
    if( i == n && sum < s )
        return ;
    if( i == n && sum == s){
        for(int j=0;j<n;++j){
            for(int k=j+1;k<n;++k){
                // printf("AS %d %d \n",A[j],A[k]);
                ans = ans + 1ll*__gcd(A[j],A[k]);
                if( ans > MOD)
                    ans-=MOD;
            }
        }
        return ;
    }
    
    int t = A[i];
    // cout<<A[i]<<"v   UPar"<<endl;
    if( A[i] == -1){
        // cout<<"DSD"<<endl;
        for(int j = 1;j<=(s-n+1);++j){
            A[i] = j;
            solve(i+1,sum+j);
         }
         A[i] = -1;
    }
    else{
        solve(i+1,sum+A[i]);
    }

    return;
}

int main()
{
    int t;
    scan(t);
    while(t--){
        ans = 0;
        scan2(n,s);
        for(int i=0;i<n;++i){
            scan(A[i]);
        }
        solve(0,0);
        cout<<ans<<endl;
    
    }
    return 0;
}
