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

    char A[4][4];
    int main()
    {
        lp(i,0,4)
            cin>>A[i];
        int flag = 0;
        lp(i,0,4)
        {
            lp(j,0,4)
            {
                if( A[i][j] == '.')
                {
                    if( i-2 >= 0 && j+2 < 4 )
                        if( A[i-1][j+1] == 'x' && A[i-2][j+2] == 'x')
                            flag =1;

                    if( j+2 < 4)
                        if( A[i][j+1] == 'x' && A[i][j+2] == 'x')
                            flag = 1;

                    if( i+2 < 4)
                        if( A[i+1][j] == 'x' && A[i+2][j] == 'x')
                            flag = 1;
                    if( i+2 < 4 && j+2 < 4)
                        if( A[i+1][j+1] == 'x' && A[i+2][j+2] == 'x')
                            flag = 1;
                }

                if( A[i][j] == 'x')
                {
                    if( i-2 >= 0 && j+2 < 4 )
                        if( (A[i-1][j+1] == '.' && A[i-2][j+2] == 'x') ||(A[i-1][j+1] == 'x' && A[i-2][j+2] == '.'))
                            flag =1;

                    if( j+2 < 4)
                        if( (A[i][j+1] == '.' && A[i][j+2] == 'x')||(A[i][j+1] == 'x' && A[i][j+2] == '.'))
                            flag = 1;

                    if( i+2 < 4)
                        if( (A[i+1][j] == '.' && A[i+2][j] == 'x')||(A[i+1][j] == 'x' && A[i+2][j] == '.'))
                            flag = 1;
                    if( i+2 < 4 && j+2 < 4)
                        if(( A[i+1][j+1] == '.' && A[i+2][j+2] == 'x')||( A[i+1][j+1] == 'x' && A[i+2][j+2] == '.'))
                            flag = 1;
                }
            }
        }
        if( flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
