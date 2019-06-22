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
    const int lim = 2e6 + 10;
    int B[lim],A[lim],result[lim],lps[lim];
    void precompute()
    {

       int i;
        B[0]=0;
        for(i=1;i< 1<<22 ;i++)
        {
            B[i] = (B[i/2] + i%2)%2;
        }
     /*   lp(i,0,15)
        {
            printf("%d ",B[i]);
        }
        printf("\n");*/
    }
    int main()
    {
        int t;
        scan(t);
        precompute();
        while(t--)
        {
            int p;
            scan(p);
            lp(i,0,p)
            {
                scan(A[i]);
                result[i] = INF;
            }
            lps[0] = 0;
            int i = 1,len = 0;
            while(i<p)
            {
                    if( A[i] == A[len])
                    {
                        len++;
                        lps[i] = len;
                        i++;
                    }
                    else
                    {
                        if(len != 0)
                        {
                            len = lps[len -1]; //most important step
                        }
                        else
                        {
                            lps[i] = 0;
                            i++;
                        }
			}
            }
         /*   lp(i,0,p)
            {
                printf("%d ",lps[i]);
                if( i ==p-1)
                    printf("\n");
            }*/
            int start = 0,j=0;
            lp(i,0,2*p-1)
            {
                if( start >= p || j >= p)
                    break;
                if( B[i] == A[j])
                {
                    result[j] = min(result[j],start);
                    j++;
                }
                else if( B[i] != A[j])
                {
                    if( j >= 1)
                       {
                           j  =  lps[j-1];
                           start = i- lps[j-1] ;
                           i = i-1;
                       }
                    else
                      {
                          start = i+1;

                      }

                }
            }
            lp(i,0,p)
            {
                if( result[i] == INF)
                    printf("-1 ");
                else
                    printf("%d ",result[i]);
            }
            printf("\n");
        }
        return 0;
    }
