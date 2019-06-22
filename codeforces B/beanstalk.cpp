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
        int t;
        scan(t);
        while(t--)
        {
            int n;
            scan(n);
            int stem = 1,flag = 0;
            lp(i,0,n)
            {
                int a;
                scan(a);
                if( a > stem)
                    flag = 1;
                stem = (stem - a)*2;
              //  printf("%d\n",stem);
            }
            if( flag == 1 || stem > 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        return 0;
    }
