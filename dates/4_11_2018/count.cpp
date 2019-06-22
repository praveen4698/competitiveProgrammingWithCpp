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
int cont[lim],A[lim],ans[lim];

int main()
{
    int n;
    memset(cont,0,sizeof(cont));
    scan(n);
    for(int i=0;i<n;++i){
        scan(A[i]);
        cont[A[i]]++;
    }
    int temp = 0;
    for(int i=1;i<=100;++i){
        if( cont[i] == 1)
            temp++;
    }
    if(temp%2 == 0){
        

    } 

    return 0;
}
