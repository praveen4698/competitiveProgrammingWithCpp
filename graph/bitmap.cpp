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
    char A[200][200];
    int dist[200][200];
    int temp[200][200];
    bool visited[200][200];

    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            lp(i,0,n)
            {
                scanf("%s",A[i]);
            }
            lp(i,0,200)
                lp(j,0,200)
                   {
                    dist[i][j] = 5;
                    visited[i][j] = false;
                   }
            queue<pii> Q;
            queue<pii> Qt;
            lp(i,0,n)
            {
                lp(j,0,m)
                {

                    Q.push(mp(i,j));

                    while(!Q.empty())
                    {
                        pii T;
                        T = Q.front();
                        Q.pop();
                        Qt.push(T);
                        visited[T.F][T.S] = true;
                      //  if( i== 0 && j == 0)
                        //    printf("%d %d\n",t.F,t.S);
                        if( A[T.F][T.S] == '1')
                        {
                            //printf("%d %d %d %d\n",t.F,t.S,i,j);
                            dist[i][j] = abs(T.F - i) + abs(T.S - j);
                           // printf("%d\n",dist[i][j]);
                            while( !Q.empty())
                                Q.pop();

                        }
                        else
                        {
                            if( (T.F+1 < n) && (visited[T.F+1][T.second] == false))
                               {
                                   Q.push(mp(T.F+1,T.S));


                               }

                            if( (T.F-1 >= 0) && (visited[T.F-1][T.second] == false))
                               {
                                   Q.push(mp(T.F-1,T.S));


                               }

                            if( (T.S-1 >= 0) && (visited[T.F][T.S-1] == false))
                               {
                                   Q.push(mp(T.F,T.S-1));


                               }

                            if( (T.S+1 < m )&& (visited[T.F][T.S+1] == false))
                               {
                                    Q.push(mp(T.F,T.S+1));


                               }
                        }
                    }
                    while(!Qt.empty())
                    {
                         pii t;
                        t = Qt.front();
                        Qt.pop();
                        visited[t.F][t.S] = false;
                    }
                }
            }

            lp(i,0,n)
            {
                lp(j,0,m)
                {
                    printf("%d ",dist[i][j]);
                }
                printf("\n");
            }

        }
        return 0;
    }

