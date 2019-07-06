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
    bool visited[251][251];
    int A[251][251],cont[62502];

    int main()
    {
        while(1)
        {
            int n,m,ans = 0;
            scan2(n,m);
            if( n == 0 && m == 0)
                break;

            lp(i,0,n)
            {
                lp(j,0,m)
                {
                    visited[i][j] = false;
                    scan(A[i][j]);
                }
            }
            lp(i,0,m*n + 1)
                cont[i] = 0;

            lp(i,0,n)
            {
                lp(j,0,m)
                {
                    if( visited[i][j] == false && A[i][j] == 1)
                    {
                        ans++;
                        queue<pii> Q;
                        Q.push(mp(i,j));
                        int temp = 0;
                        while(!Q.empty())
                        {
                            pii t = Q.front();
                            Q.pop();
                            int a = t.F;
                            int b = t.S;
                            if( visited[a][b] == false)
                            {
                                temp++;
                                visited[a][b] = true;
                                if( a-1 >= 0 && visited[a-1][b] == false && A[a-1][b] == 1 )
                                    Q.push(mp(a-1,b));
                                if( a+1 < n && visited[a+1][b] == false && A[a+1][b] == 1 )
                                    Q.push(mp(a+1,b));
                                if( b-1 >= 0 && visited[a][b-1] == false && A[a][b-1] == 1 )
                                    Q.push(mp(a,b-1));
                                if( b+1 < m && visited[a][b+1] == false && A[a][b+1] == 1 )
                                    Q.push(mp(a,b+1));
                            }
                        }
                        cont[temp]++;
                    }
                }
            }

            printf("%d\n",ans);
            lp(i,0,n*m+1)
                if( cont[i] > 0)
                    printf("%d %d\n",i,cont[i]);

        }
        return 0;
    }
