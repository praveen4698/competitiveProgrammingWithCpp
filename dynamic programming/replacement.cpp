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

    int A[100001];
    int main()
    {
        int n;
        scan(n);
        lp(i,0,n)
        {
            scan(A[i]);
        }
        sort(A,A+n);
        int maxi = 1;
        if( n == 1 && A[0] == 1)
         {
             printf("2\n");
             return 0;
         }

        printf("%d ",maxi);
        lp(i,1,n)
        {
            if( i == n-1 && A[i] == 1)
             {
                 printf("2\n");
                 continue;
             }
            maxi = max( maxi ,A[i-1]);
            printf("%d ",maxi);
        }
        return 0;
    }
