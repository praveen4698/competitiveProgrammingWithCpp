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
int cont[lim];
int main()
{
    int n,k;
    scan2(n,k);
    memset(cont,0,sizeof(cont));
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        cont[a]++;
    }
    for(int i=0;i<=lim;++i){
        if( cont[i] > 0){
            A.push_back(cont[i]);
        }
    }
    sort(all(A));
    reverse(all(A));
    int th = A[k-1];
    for(int i=0;i<=lim;++i){
        if( cont[i] >= th){
            ans.push_back(i);
        }
        if( ans.size() == k){
            break;
        }
    }
    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}
