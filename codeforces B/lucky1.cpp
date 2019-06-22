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
    const int lim = 1e5+10;
    int dp[lim],R[lim];
    int Rsum(int x,int r)
    {
        int value = 0;
        while(x>0)
        {
            if( x%10 == r)
                value++;
            x = x/10;
        }
        return value;
    }

    int main()
    {
        int sum_4= 0,sum_7 = 0,res = 0;
        dp[0] = 1;
        lp(i,1,lim)
        {
            sum_4 = sum_4 + Rsum(i,4);
            sum_7 = sum_7 + Rsum(i,7);
            res+=dp[sum_4 - sum_7];
            R[i] = res;
            dp[sum_4 - sum_7]++;

        }
        int t;
        scan(t);
        while(t--)
        {
            int n;
            scan(n);
            printf("%d\n",R[n]);
        }
        return 0;
    }
