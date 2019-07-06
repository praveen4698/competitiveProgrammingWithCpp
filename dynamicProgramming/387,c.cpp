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
        int A[102],t,s,d,n,Q;
        lp(i,0,101)
            A[i] = 0;
        scan2(n,Q);
        while(Q--)
        {
            int counti = 0;
            scan3(t,s,d);
            int sum = 0;
            lp(i,1,n+1)
            {
                if( A[i] <  t)
                {
                  counti++;
                  A[i] = d+t-1;
                  if( counti <= s)
                    sum += i;

                }

            }
            if( counti < s)
                printf("-1\n");
            else
                printf("%d\n",sum);


        }
        return 0;
    }
