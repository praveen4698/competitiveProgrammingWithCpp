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
    const int lim = 2e5+10;
    int A[lim];
    int main()
    {
        int n;
        scan(n);
        lp(i,1,n+1)
            scan(A[i]);

        lp(i,1,n+1)
        {
            if( n%2 == 1){


            if( i%2 == 1 )
                printf("%d ",A[n-i+1]);
            else
                printf("%d ",A[i]);}

            else
            {
                if( i%2 == 1 && i <= n/2 )
                    printf("%d ",A[n-i+1]);
                else if( i%2 == 0 && i <= n/2)
                    printf("%d ",A[i]);
                else if( i %2 == 1)
                    printf("%d ",A[i]);
                else
                    printf("%d ",A[n-i+1]);
            }
        }
        return 0;
    }
