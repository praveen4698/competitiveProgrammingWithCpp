#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b) scanf("%d %d %d",&a,&b,&c)
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
    const int lim = 1e7 + 10;
    ll cont[lim],mns[lim];


    int main()
    {
        int x,n,k;
        scan2(n,k);
        lp(i,0,n)
            scan(x),cont[x]++;
        ll cur = 0;
        lpr(i,lim-1,1)
        {
            cur+=cont[i];
            cur-=mns[i];
            cont[i/2]+=cont[i];
            cont[(i+1)/2]+=cont[i];
            mns[(i+1)/2]+=cont[i];
            if( cur >= k)
            {
                printf("%d",i);
                return 0;
            }
        }
        printf("-1");
        return 0;
    }
