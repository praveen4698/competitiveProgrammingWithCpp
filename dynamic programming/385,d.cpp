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

    char A[1001][1001];
    int main()
    {
        int n,m;
        scan2(n,m);
        lp(i,0,n)
        {
            scanf("%s",A[i]);
        }
        int cont = 0;
        int maxx = -1,minx = INF,maxy = -1,miny = INF;
        lp(i,0,n)
        {
            lp(j,0,m)
            {
                if( A[i][j] == 'X')
                {
                    maxx = max(maxx,i);
                    minx = min(minx,i);
                    maxy = max(maxy,j);
                    miny = min(miny,j);
                    cont = cont + 1;
                }
            }
        }
        int area = (maxx - minx + 1)*(maxy - miny + 1);
        if( area == cont )
            printf("YES");
        else
            printf("NO");
        return 0;
    }
