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

    int G[51][51];
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int n;
            scan(n);
            set<int> v;
            bool r = false;
        lp(i,0,n)
            lp(j,0,n)
                scan(G[i][j]);
        lp(i,0,n)
            v.insert(i);

        while(!v.empty())
        {
            if( v.size() == 1)
                break;
            r = false;
            for(int x : v)
            {
                set<int> value;
                for( int y : v)
                {
                    if( x != y)
                        value.insert(G[x][y])
                }
                if( value.size() == 1)
                {
                    r = true;
                    v.erase(x);
                    break;
                }
            }
            if( r == false)
                break;
        }
        printf("%d\n",v.size());


        }
        return 0;
    }
