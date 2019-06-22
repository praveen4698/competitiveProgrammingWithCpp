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
    const ll mod = 1e9 + 7;
    ll sum[100001];
    ll A[10],prev[10];
    void pre_compute()
    {
        sum[0] = 0;
        lp(i,0,10)
            prev[i] = 1;
        sum[1] = 10;
        lp(i,2,100001)
        {
            sum[i] = 0;
            A[0] = prev[7];
            A[1] = prev[2]+prev[4];
            A[2] = prev[1] + prev[3] + prev[5];
            A[3] = prev[2] + prev[6];
            A[4] = prev[1]+prev[5]+prev[7];
            A[5] = prev[2] + prev[4] + prev[6] + prev[8];
            A[6] = prev[3] + prev[5] + prev[9];
            A[7] = prev[4] + prev[8] + prev[0];
            A[8] = prev[5] + prev[7] + prev[9];
            A[9] = prev[6] + prev[8];
            lp(j,0,10)
            {
                prev[j] = A[j]%mod;
                sum[i] = sum[i] + prev[j];
                sum[i] = sum[i]%mod;
            }
        }
    }

    int main()
    {
        pre_compute();
        int t;
        scan(t);
        while(t--)
        {
            int n;
            scan(n);
            printf("%lld\n",sum[n]);
        }
        return 0;
    }
