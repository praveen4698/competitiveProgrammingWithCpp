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


    int main()
    {
        queue<int> q1,q2;
        int n;
        scan(n);
        int k1,k2;
        scan(k1);
        lp(i,0,k1)
        {
            int a;
            scan(a);
            q1.push(a);
        }
        scan(k2);
        lp(i,0,k2)
        {
            int a;
            scan(a);
            q2.push(a);

        }
        int  counti = 0;
        while(1)
        {
            if( q1.empty())
            {
                printf("%d 2",counti);
                return 0;
            }
            if( q2.empty())
            {
                printf("%d 1",counti);
                return 0;
            }
            if(counti == 1000)
            {
                printf("-1");
                return 0;
            }

            int a = q1.front();
            q1.pop();
            int b = q2.front();
            q2.pop();
            if( a > b)
            {
                q1.push(b);
                q1.push(a);
            }
            else
            {
                q2.push(a);
                q2.push(b);
            }
            counti++;
        }
        return 0;
    }

