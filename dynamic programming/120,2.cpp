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

    int A[1001][1001];
    int main()
    {
        int n,k;
        scan2(n,k);
        lp(i,1,n+1)
            lp(j,1,n+1)
                A[i][j] = 0;
        lp(i,0,k)
        {
            int a,b;
            scan2(a,b)
            A[a][b] = 1;
        }
        if( n <= 2)
        {

            printf("-1");
            return 0;

        }
        int counti = 9;
        lp(i,1,n-2)
        {
            lp(j,1,n-2)
            {
                int a = i;
                int b = j;
                int temp = 0;
                lp(k,a,a+3)
                    {
                        lp(l,b,b+3)
                        {
                            if( A[k][l] == 0)
                                temp++;
                        }
                    }

                if( temp < counti)
                    counti = temp;

            }
        }
        printf("%d",counti);
        return 0;
    }
