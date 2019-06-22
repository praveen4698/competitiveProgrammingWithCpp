#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dis[1001][1001];
    char A[1001][1001];
    struct compare
    {
        bool operator()(const pair<int,pair<int, int> > l,const pair<int,pair<int, int> > r)
			{
				return l.first > r.first;
			}
    };
    bool vis[1001][1001];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int r,c;
            scanf("%d %d",&r,&c);
            for(int i=0;i<r;++i)
                for(int j=0;j<c;++j)
                    dis[i][j] = INF,vis[i][j] = false;
            for(int i = 0;i<r;++i)
                scanf("%s",A[i]);

            dis[0][0] = 0;
        //priority_queue< pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,compare > Q;
        //queue< pair<int,pair<int,int> > > Q;
        deque< pair<int,pair<int,int> > > Q;
        Q.push_front(make_pair(0,make_pair(0,0)));
        while(!Q.empty())
        {
            pair<int,pair<int,int> > tt = Q.front();
            Q.pop_front();
            int x = tt.second.first;
            int y = tt.second.second;
            int dist = tt.first;
            vis[x][y] = true;
            if( (x-1 >= 0) )
            {
                if( A[x][y] == A[x-1][y] && dis[x][y] < dis[x-1][y] )
                {
                    dis[x-1][y] = dis[x][y];
                    Q.push_front(make_pair(dis[x-1][y],make_pair(x-1,y)));
                }
                else if( A[x][y] != A[x-1][y] && (dis[x][y]+1) < dis[x-1][y] )
                {
                    dis[x-1][y] = dis[x][y]+1;
                    Q.push_back(make_pair(dis[x-1][y],make_pair(x-1,y)));
                }

            }
            if( (x+1 < r))
            {
                if( A[x][y] == A[x+1][y] && dis[x][y] < dis[x+1][y] )
                {
                    dis[x+1][y] = dis[x][y];
                    Q.push_front(make_pair(dis[x+1][y],make_pair(x+1,y)));
                }
                else if( A[x][y] != A[x+1][y] && (dis[x][y]+1) < dis[x+1][y] )
                {
                    dis[x+1][y] = dis[x][y]+1;
                    Q.push_back(make_pair(dis[x+1][y],make_pair(x+1,y)));
                }

            }
            if( (y-1 >= 0))
            {
                if( A[x][y] == A[x][y-1] && dis[x][y] < dis[x][y-1] )
                {
                    dis[x][y-1] = dis[x][y];
                    Q.push_front(make_pair(dis[x][y-1],make_pair(x,y-1)));
                }
                else if( A[x][y] != A[x][y-1] && (dis[x][y]+1) < dis[x][y-1] )
                {
                    dis[x][y-1] = dis[x][y]+1;
                    Q.push_back(make_pair(dis[x][y-1],make_pair(x,y-1)));
                }

            }
            if( (y+1<c) )
            {
                if( A[x][y] == A[x][y+1] && dis[x][y] < dis[x][y+1] )
                {
                    dis[x][y+1] = dis[x][y];
                    Q.push_front(make_pair(dis[x][y+1],make_pair(x,y+1)));
                }
                else if( A[x][y] != A[x][y+1] && (dis[x][y]+1) < dis[x][y+1] )
                {
                    dis[x][y+1] = dis[x][y]+1;
                    Q.push_back(make_pair(dis[x][y+1],make_pair(x,y+1)));
                }

            }
        }
        printf("%d\n",dis[r-1][c-1]);

        }
        return 0;
    }
