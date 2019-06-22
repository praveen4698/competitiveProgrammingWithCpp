#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 10000000;
    bool isprime[lim + 10];
    int lo[lim +10];
    int maxx[lim+10];
    void primegen()
    {
        lp(i,0,lim+1)
        {
            isprime[i] = true;
            lo[i] = i;
        }
        lp(i,2,lim+1)
        {
            if( isprime[i])
            {
                for(int j = i ; j <= lim;j = i+j)
                {
                    if( isprime[j])
                    {
                        isprime[j] = false;
                        lo[j] = i;
                    }
                }
            }
        }
    }
    int main()
    {
        primegen();
        int t;
        scan(t);
        while(t--)
        {
            memset(maxx,0,sizeof(maxx));
            int n;
            scan(n);
            int ans = 0;
            lp(i,0,n)
            {
                int a;
                scan(a);
                int a1 = a,Max = 1;
                while(a > 1)
                {
                    Max = max( Max,1+maxx[lo[a]]);
                    a/=lo[a];
                }
                ans = max( ans,Max);
                a = a1;
                while( a >1)
                {
                    maxx[lo[a]] = Max;
                    a/=lo[a];
                }
            }
            printf("%d\n",ans);

        }
        return 0;
    }
