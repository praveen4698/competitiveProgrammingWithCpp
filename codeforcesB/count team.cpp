#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
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


    int main()
    {
        int res = 0;
        int n,m;
        scan2(n,m);
        while(m>0 && n>0)
        {
            if( m > n)
            {
                m-=2;
                n-=1;
                if( m >= 0 && n >= 0)
                   res++;
            }
            else
            {
                m-=1;
                n-=2;
                if( m >= 0 && n >= 0)
                    res++;
            }
        }
        printf("%d",res);
        return 0;
    }
