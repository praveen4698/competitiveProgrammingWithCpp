#include<bits/stdc++.h>
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

const int lim = 700;
bitset<700>  done[lim][lim],dp[lim][lim];
int GCD[lim][lim];
int A[lim];
bool solve(int l,int r,int x){
    if(done[l][r][x]){
        return dp[l][r][x];
    }
    if( l >= r){
        return true;
    }

    bool left = false;
    if( l == x)
        left = true;
    for(int i=l;i<x;++i){
        if(solve(l,x-1,i) && GCD[i][x] > 1){
            left = true;
            break;
        }
    }
    bool right = false;
    if( r == x)
        right = true;
    for(int i=x+1;i<=r;++i){
        if(solve(x+1,r,i) && GCD[i][x] > 1){
            right = true;
            break;
        }


    }
    dp[l][r][x] = left && right;
    done[l][r][x] = true;
    return dp[l][r][x];

}
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i){
        scan(A[i]);
    }
    memset(dp,false,sizeof(dp));
    memset(done,false,sizeof(done));
    int flag = 0;
    for(int i=0;i<n;++i){
        int cont = 0;
        for(int j=0;j<n;++j){
            GCD[i][j] = __gcd(A[i],A[j]);
            if(GCD[i][j] == 1 )
                cont++;
        }
        if( cont == n-1){
            flag = 1;
            break;
        }
    }
    if( flag == 1){
        
        printf("No");
        return 0;
    }
    for(int i=0;i<n;++i){
        if( solve(0,n-1,i)){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}

