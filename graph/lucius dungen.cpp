#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

		struct compare{
			bool operator()(const pair<pii,int> l,const pair<pii,int> r)
			{
				return l.second > r.second;
			}


		};

    int main()
    {
        int dist[101][101];
        int A[101][101];
        bool visited[101][101];
        int Z;
        scanf("%d",&Z);
        while(Z--)
        {
            int n,m;
            cin>>n>>m;
            lp(i,1,n+1)
            {
                lp(j,1,m+1)
                {
                    cin>>A[i][j];
                    dist[i][j] = INF;
                    visited[i][j] = false;
                }
            }

            priority_queue <pair<pii ,int> , vector<pair<pii,int> > , compare> Q;
            dist[1][1] = A[1][1];
            Q.push(mp(mp(1,1),A[1][1]));
            while(!Q.empty())
            {
                pair<pii,int> T = Q.top();
                int k = T.first.first;
                int l = T.first.second;
                visited[k][l] = true;
                int weight = T.second;
                Q.pop();
                lp(i,k-1,k+2)
                {
                    lp(j,l-1,l+2)
                    {
                        if( i > 0 && i < n+1 && j > 0 && j < m+1)
                        {
                            int diffk = abs( i - k);
                            int diffl = abs(j -l);
                            if( diffk + diffl == 1 && visited[i][j] == false && dist[i][j] > A[i][j] + weight)
                            {
                                dist[i][j] = A[i][j] + weight;
                                Q.push(mp(mp(i,j),dist[i][j]));
                            }
                        }

                    }
                }
            }
          /*  lp(i,1,n+1)
            {
                lp(j,1,m+1)
                {
                    cout<<dist[i][j]<<" ";
                   // dist[i][j] = INF;
                   // visited[i][j] = false;
                }
                printf("\n");
            }  */

            int x,y,t;
            cin>>x>>y>>t;
            if( dist[x][y] <= t)
            {
               printf("Yes\n%d\n",t-dist[x][y]);
            }
            else
            {
                printf("No\n");
            }
        }

        return 0;
    }
