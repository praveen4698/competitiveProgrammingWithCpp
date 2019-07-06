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
        int n,k;
        scan2(n,k);
        int x = 1;
        int counti = 1;
        int round = 0;
        lp(i,0,n)
        {
            counti++;
            int flag = 0;
            if( x+k > n)
            {
                round++;
                flag = 1;
                x = x+k-n;
            }
            else
            {
                x = x+k;
            }
            counti = counti  + 2*round;
            if( flag == 1)
                counti = counti -1;
            if( i == n-1)
                counti = counti - 1;

            printf("%d ",counti);
        }
        return 0;
    }

