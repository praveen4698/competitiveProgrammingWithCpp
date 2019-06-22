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
        int x,n,a,b,da,db;
        scan2(x,n);
        scan2(a,b);
        scan2(da,db);
        int flag = 0;
        if( x == 0)
        {
            printf("YES\n");
            return 0;
        }
        lp(i,0,n)
        {

            lp(j,0,n)
            {
                if( (a- i*da) + (b - j*db) == x || (a-i*da) == x || (b - j*db) == x)
                {
                    flag = 1;
                }

            }

        }
        if( flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
