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
    const int lim = 1e5 + 10;
    int M[lim];
    vector<int> A[lim];
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int n,k;
            scan2(n,k);
            lp(i,0,n+1)
                A[i].clear();
            lp(i,0,k+1)
                M[i] =0;
            lp(i,0,n)
            {
                int a;
                scan(a);
                lp(j,0,a)
                {
                    int b;
                    scan(b);
                    A[i].pb(b);
                    M[b]++;
                    //printf("%d\n",j);
                }
               // printf("%d\n",i);
            }
            int flag = 0;
            lp(i,1,k+1)
            {
                if( M[i] == 0)
                    flag = 1;

            }
            if( flag == 1)
                printf("sad\n");
            else
            {
                flag = 0;
                lp(i,0,n)
                {
                    int flag2 = 0 ;
                    lp(j,0,A[i].size())
                    {
                        if( M[A[i][j]] == 1)
                            flag2 = 1;
                    }
                    if( flag2 == 0)
                        flag  = 1;
                }
                if( flag == 1)
                    printf("some\n");
                else
                    printf("all\n");
            }
        }
        return 0;
    }


