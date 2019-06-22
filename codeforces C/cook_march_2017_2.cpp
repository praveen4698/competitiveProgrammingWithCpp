#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int r,b,pr,pb;
    double rl,bl,ans;
    void RED()
    {
        double p = (rl)/(rl + bl);
        ans+=p;
        rl=-p;
        bl=-(1-p);
        pr--;
    }
    void BLUE()
    {
        double p = (bl)/(rl + bl);
        ans+=p;
        rl=-(1-p);
        bl=-p;
        pb--;
    }
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            scan3(r,b,pr);
            pb = r+b-pr;
            ans = 0;
            rl = r;
            bl = b;
            lp(i,0,r+b)
            {
                if( pr == 0)
                    BLUE();
                else if(pb == 0)
                    RED();
                else if( rl > bl )
                    RED();
                else
                    BLUE();
            }
            printf("%0.10f\n",ans);
        }
        return 0;
    }
