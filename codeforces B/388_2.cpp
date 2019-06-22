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
        int x[3],y[3];
        scan2(x[0],y[0]);
        scan2(x[1],y[1]);
        scan2(x[2],y[2]);
        printf("3\n");
        printf("%d %d\n",x[0]+x[1]-x[2],y[0]+y[1]-y[2]);
        printf("%d %d\n",x[0]-x[1]+x[2],y[0]-y[1]+y[2]);
        printf("%d %d\n",-x[0]+x[1]+x[2],-y[0]+y[1]+y[2]);
        return 0;
    }
