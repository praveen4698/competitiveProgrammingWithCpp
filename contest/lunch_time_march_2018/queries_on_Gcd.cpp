 #include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
const int lim = 10001;
int ans[lim][lim];
int A[lim];
inline int gcd(int a, int b, int c) {
	return a < c ? a : (b == 0 ? a : gcd(b, a % b, c));
}
int main()
{
    int n;
    scan(n);
    int q;
    scan(q);
    for(int i=1;i<=n;++i)
        scan(A[i]);
    for(int i=n;i>=1;--i)
    {
        for(int j=i+1;j<=n;++j)
        {
            ans[i][j] = max(ans[i][j-1],ans[i+1][j]);
            ans[i][j] = max(ans[i][j],gcd(A[i],A[j],ans[i][j]));
          //  cout<<__gcd(A[i],A[j])<<endl;
        }
    }
    while(q--)
    {
        int l,r;
        scan2(l,r);
        printf("%d\n",ans[l][r]);
    }
    return 0;
}


