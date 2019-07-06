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
    const ll mod = 1e13;
    ll  A[10000001];
    ll  B[10000001];
    int main()
    {
        A[0] = 0;
        A[1] = 1;
        lp(i,0,10000000)
            B[i] = 0;
        lp(i,2,10000000)
        {
            A[i] = (A[i-1] + A[i-2])%mod;
            B[A[i]] = 1;
        }
        lp(i,1,100)
        {
           if( B[i] == 0)
            printf("%d\n",i);
        }
        return 0;
    }
