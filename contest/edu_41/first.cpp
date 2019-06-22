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

const int lim = 1001;
int A[lim];
int main()
{
    memset(A,0,sizeof(A));
    int n,m;
    scan2(n,m);
    int ans = 0;
    for(int i=0;i<m;++i)
    {
        int a;
        scan(a);
        A[a]++;
        int temp = 0;
        for(int j=1;j<=n;++j)
        {
            if( A[j] > 0)
                temp++;
        }
        if( temp == n)
        {
            ans++;
            for(int j=1;j<=n;++j)
                A[j]--;
        }

    }
    cout<<ans<<endl;
    return 0;
}


