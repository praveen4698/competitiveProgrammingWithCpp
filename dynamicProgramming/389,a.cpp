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

    char A[1001],B[1001];
    int g[101][101];
    int main()
    {
        scanf("%s %s",A,B);
        int n = strlen(A);
        lp(i,0,n)
        {
            int a = A[i] - 'a';
            int b = B[i] - 'a';
            g[a][b] = g[b][a] = 1;
        }
        lp(i,0,26)
        {
            int counti = 0;
            lp(j,0,26)
            {
                counti+=g[i][j];
            }
            if( counti > 1)
            {
                printf("-1");
                return 0;
            }
        }

        int res = 0;
        lp(i,0,26)
            lp(j,i+1,26)
                res+=g[i][j];

        printf("%d\n",res);
        lp(i,0,26)
            lp(j,i+1,26)
            {
                if( g[i][j] == 1)
                    printf("%c %c\n",char(i + 'a') ,char(j+'a'));
            }
        return 0;
    }
