#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
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

    map<char,int> M;
    int main()
    {
        M['B'] = 0;
        M['C'] = 0;
        int n,m;
        scan2(n,m);
        lp(i,0,n)
        {
            lp(j,0,m)
            {
                char a;
                cin>>a;

                if( a == 'W' || a == 'B' || a == 'G')
                    M['B']++;
                else
                {
                   M['C']++;
                  // printf("%d %d\n",i,j);
                }
            }
        }
        //printf("%d \n",M['C']);
        if( M['C'] > 0)
            printf("#Color");
        else
            printf("#Black&White");
        return 0;
    }
