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
    const int lim = 1e6 + 10;
    long long int A[lim + 5];
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int n,k;
            scan2(n,k);
            lp(i,0,lim)
            {
                A[i] = 0;
            }
            lp(i,0,n)
            {
                ll a;
                cin>> a;
                int s = (int)(a%k);
                A[s]++;
            }
            int ans = 0;
            lp(i,0,k)
            {
               // printf("i = %d %d\n",i,A[i]);
            }
            lp(i,1,k/2 )
            {
                ans = ans + max(A[i],A[k-i]);
                //printf("%d\n",ans);
            }
            if( (A[k/2] > 0) && (k%2 == 0))
            {
                ans++;
              //  printf("y0\n");
            }
            if( A[0] > 0)
                ans++;
            printf("%d\n",ans);
        }
        return 0;
    }


