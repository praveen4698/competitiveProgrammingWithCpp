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
    const int lim = 2e6 + 10;
    int A[lim],sum[lim];
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int q1,q2;
            scan2(q1,q2);
            lp(i,0,q1*q2)
                scan(A[i]);
            lp(i,0,q1*q2)
                A[i+q1*q2] = A[i];
            sum[0] = A[0];
            lp(i,1,2*q1*q2)
                sum[i] = sum[i-1] + A[i];
            int flag = 0;
         //   lp(i,0,2*q1*q2)
         //   {
         //       printf("%d %d\n",A[i],sum[i]);
         //   }
            lp(i,0,q2)
            {
                int temp = 0;
                int start = i;
                int endi = i+q2-1;
                lp(j,0,q1)
                {
                   // printf("%d %d\n",start,endi);
                    if( start == 0)
                    {
                        if( sum[endi] > q2/2)
                            temp++;
                    }
                    else if( sum[endi] - sum[start-1] > q2/2)
                    {
                        temp++;
                    }
                    start = endi+1;
                    endi = endi+q2;

                }
               // printf("temp -- %d\n",temp);
                if(temp > q1/2)
                {
                    flag = 1;
                    break;
                }
            }
            if( flag == 1)
                printf("1\n");
            else
                printf("0\n");
        }
        return 0;
    }

