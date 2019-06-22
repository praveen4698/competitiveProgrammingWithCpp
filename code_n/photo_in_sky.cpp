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

const int lim = 2e5+10;
int A[lim];
int main()
{
    int n;
    scan(n);
    for(int i=0;i<2*n;++i)
        scan(A[i]);
    sort(A,A+2*n);
    printf("%lld",(A[n-1]-A[0])*1ll*(A[2*n-1]-A[n]));
    return 0;
}