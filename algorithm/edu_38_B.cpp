#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
vector<int> A;

int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        int a;
        scan(a);
        A.pb(a);
    }
    sort(all(A));
    int lim = 1000000;
    int ans = min(A[n-1]-1,lim-A[0]);
    for(int i=0;i<n-1;++i)
    {
        ans = min(max(A[i]-1,lim-A[i+1]),ans);
    }
    cout<<ans<<endl;
    return 0;
}


