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

    char A[1001][1001];
    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,m;
            scan2(n,m);
            lp(i,0,n)
                scanf("%s",A[i]);
            int flag = 0;
          /*  if( n == 1 && m == 1)
            {
                printf("yes\n");
                continue;
            }*/
            lp(i,0,n)
            {
                lp(j,0,m)
                {
                    if( A[i][j] == 'B' )
                    {  // printf("yoB\n");
                        if( i+1 < n && A[i+1][j] == 'A')
                            flag = 1;
                        //if( i+1 < n && A[i+1][j] == 'W')
                          //  flag = 1;
                    }
                    if( A[i][j] == 'W' )
                    {
                       // printf("yoW\n");
                        if( i == n  )
                            flag = 1;
                        else if( A[i+1][j] == 'A')
                            flag = 1;

                        if( j == 0)
                            flag = 1;
                        else if( A[i][j-1] == 'A')
                            flag = 1;

                        if( j == m)
                            flag = 1;
                        else if( A[i][j+1] == 'A')
                            flag = 1;


                    }
                }
            }
            if( flag == 1)
                printf("no\n");
            else
                printf("yes\n");
        }
        return 0;
    }
