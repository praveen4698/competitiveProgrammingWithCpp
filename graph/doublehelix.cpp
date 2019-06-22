#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
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

    int A[10001],B[10001];
    int suma[10001],sumb[10001];
    int main()
    {
        int n,m;
        while(1)
        {
            scan(n);
            if( n == 0)
                break;
            suma[0] = 0;
            lp(i,1,n+1)
             {
                 scan(A[i]);
                 suma[i] = suma[i-1] + A[i];
             }
            scan(m);
            sumb[0] = 0;
            lp(i,1,m+1)
            {
                scan(B[i]);
                sumb[i] = sumb[i-1] + B[i];
            }
            int i=1,j=1,preva = 0,prevb = 0;
            int count = 0;
            while( i <= n && j <= m)
            {
                if( A[i] > B[j])
                    j++;
                else if ( A[i] < B[j])
                    i++;
                else if( A[i] == B[j])
                {
                    int diffa = suma[i] - suma[preva];
                    int diffb = sumb[j] - sumb[prevb];

                    if( diffa > diffb)
                        count = count + diffa;
                    else
                        count = count + diffb;

                    preva = i;
                    prevb = j;
                    i++;
                    j++;
                }
            }

            int diffa = suma[n]- suma[preva];
            int diffb = sumb[m] - sumb[prevb];
            if( diffa > diffb)
                count = count + diffa;
            else
                count = count + diffb;

            printf("%d\n",count );
        }
        return 0;
    }

