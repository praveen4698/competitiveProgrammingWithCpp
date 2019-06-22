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

int A[1001];
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,u,d;
        scan3(n,u,d);
        for(int i=0;i<n;++i)
            scan(A[i]);
        int use = 0;
        int ans = -1;
        for(int i=1;i<n;++i)
        {
            int flag = 0;
            if( A[i] > A[i-1])
            {
                if( A[i]-A[i-1] > u)
                {
                    ans = i;
                    flag = 1;
                    break;

                }


            }
            else
            {
                if( A[i-1] - A[i] > d)
                {
                    if( use == 1)
                    {
                        ans = i;
                        flag = 1;
                        break;

                    }
                    else
                        use++;
                }
            }
            if( flag == 1)
                break;

        }
        if( ans == -1)
            cout<<n<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}


