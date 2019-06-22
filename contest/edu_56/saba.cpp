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
const int lim = 101;
int n,m;
string A[lim];
int check(int i,int j){
    int cont = 0;
    if(i+3 < n){
        if( A[i][j] == 's' && A[i+1][j] == 'a' && A[i+2][j] == 'b' && A[i+3][j] == 'a')
            cont++;
    }
    if(j+3 < m){
        if( A[i][j] == 's' && A[i][j+1] == 'a' && A[i][j+2] == 'b' && A[i][j+3] == 'a')
            cont++;
    }
    if(i+3 < n && j+3< m){
        if( A[i][j] == 's' && A[i+1][j+1] == 'a' && A[i+2][j+2] == 'b' && A[i+3][j+3] == 'a')
            cont++;
    }
    if(i-3 >= 0 && j+3< m){
        if( A[i][j] == 's' && A[i-1][j+1] == 'a' && A[i-2][j+2] == 'b' && A[i-3][j+3] == 'a')
            cont++;
    }
    return cont;
}

int main()
{
    scan2(n,m);
    int ans = 0;
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans+=check(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
