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

    vector<pair<int,pii> > A[100001];
    int cost[33][33];
    int calc(int l1,int r1,int l2,int r2)
    {
        int temp = max(r2,r1) - min(l1,l2) + 1;
        return (temp - (r2 - l2 + 1));
    }
    int main()
    {
        int n,m;
        scan2(n,m);
        lp(i,0,m)
        {
            int a,b,c,d;
            scan2(a,b);
            scan2(c,d);
            A[a].pb(mp(b,mp(c,d)));
        }
        lp(i,1,33)
            lp(j,1,33)
                cost[i][j] = INF;

        lp(l,1,33)
        {
            lp(r,1,33)
            {

                lp(k,0,A[1].size())
                {
                    int next = A[1][k].F;
                    int spent = calc(l,r,A[1][k].S.F,A[1][k].S.S);
                    while(A[next].size() > 0)
                    {
                        spent = spent + calc(l,r,A[next][0].S.F,A[next][0].S.S);
                        next = A[next][0].F;
                    }
                    cost[l][r] = min(cost[l][r],spent);
                }
            }
        }

        lp(r,1,33)
        {
            lp(l,1,r+1)
            {
                lp(m,l,r+1)
                {
                    cost[l][r] = min(cost[l][r] , cost[l][m]+ cost[m+1][r]);
                }
            }
        }

        printf("%d\n",cost[1][32]);
        return 0;
    }
