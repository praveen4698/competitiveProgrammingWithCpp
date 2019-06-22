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


    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,m,k,c;
            long double p1,p2,p;
            scan2(n,m);
            scan2(k,c);
            if( n%2 == 0 && m%2 == 0)
                p1 = 1.0000000;
            else
                p1 = 0.0000000;
            if(n%2 == 1 && m%2 == 1)
                p2 = 0.000000;
            else
                p2 = 1.0000000;

            p = 0.5*p1 + 0.5*p2;
          //  printf("%.15f\n",p);
            if(c==0||k==0)cout<<1.0<<endl;
            else if( p > 0.6 || p < 0.4)
            {
                cout << setprecision(12) << p;
                 printf("\n");
            }

            else
            {

                long double ans = 1.00;
                int count2 = 0;
                ll k1 = c;
                lpr(i,k,1)
                {
                    ans = ans*(long double)k1/(long double)i;
                    k1--;
                   // printf("ans1 = %.15f\n",ans);
                    while(ans > 1000000000.00000000)
                    {
                        ans = ans/(long double)2;
                        count2++;
                    }
                }

                lp(i,count2,c)
                {
                    ans = ans/2;
                }
             //   printf("ans = %.15f\n",ans);
                long double prev = ans ;
                lp(i,k+1,c+1)
                {
                    long double temp = prev*(c-i+1)/i;
                    ans = ans + temp;
                    prev = temp;
                }

                 cout << setprecision(12) << ans;
                 printf("\n");
            }

        }
        return 0;
    }
