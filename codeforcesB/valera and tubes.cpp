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
        int n,k,m;
        scan(n);
        scan(m);
        scan(k);
        int temp = 0,counti = 0;
        lp(i,1,n+1)
        {
            lp(j,1,m+1)
            {
                if( temp == 0 && counti != k-1)
                {
                    printf("2");
                    counti = counti + 1;

                }
                else if( temp == 0 && counti == k-1)
                {
                    printf("%d",n*m-2*(k-1));
                    counti = counti +1;
                }
                if( i%2 == 1)
                    printf(" %d %d",i,j);
                else
                    printf(" %d %d",i,m-j+1);
                temp = temp + 1;
                if(temp == 2 && counti != k)
                {
                    //printf("yo\n");
                    temp = 0;
                    printf("\n");
                }
            }
        }
        return 0;
    }

