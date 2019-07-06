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
    const int lim = 2e5 + 10;
    char A[lim];

    int main()
    {
        int n;
        scan(n);
        scanf("%s",A);
        int ans = 1;
        char curx = '$',cury = '$';
        lp(i,0,n)
        {
            char c = A[i];
            if( c == 'L' || c == 'R')
            {
                if( curx == '$')
                    curx = c;
                else if( curx != c)
                {
                    ans++;
                    curx = c;
                    cury =  '$';
                }
            }
            else
            {
                if( cury == '$')
                    cury = c;
                else if( cury != c)
                {
                    ans++;
                    cury = c;
                    curx = '$';
                }
            }
        }
        printf("%d",ans);
        return 0;
    }
