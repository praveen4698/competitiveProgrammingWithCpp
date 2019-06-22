#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<int> A[10001];
    int parent[10001];
    int parin(int x)
    {
        if( parent[x] == -1)
            return x;
        parent[x] = parin(parent[x]);
        return parent[x];
    }
    struct compare{
			bool operator()(const pair<int,pair<int,int> >  l,const pair<int,pair<int,int> > r)
			{
				return l.first > r.first;
			}
    };
    int main()
    {

            int n ,m;
            scanf("%d %d",&n,&m);
            for(int i=0;i<n;++i)
            {
                A[i].clear();
                parent[i+1] = -1;
            }
            priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > > ,compare> Q;
            for(int i=0;i<m;++i )
            {
                int u,v,a;
                scanf("%d %d %d",&u,&v,&a);
                int x ;
                if( a == 0)
                {
                    Q.push(make_pair(0,make_pair(u,v)));
                }
                else
                {
                    int xx;
                    scanf("%d",&xx);
                    Q.push(make_pair(xx,make_pair(u,v)));
                }
            }
            int cont = 0;
            int ans = 0;
            while(!Q.empty())
            {
                pair<int,pair<int,int> > t = Q.top();
                Q.pop();
                int cost = t.first;
                int x = t.second.first;
                int y = t.second.second;
                int fx = parin(x);
                int fy = parin(y);
                if( fx != fy)
                {
                    ans+=t.first;
                    parent[x] = y;
                    cont++;
                }
                if( cont == n-1)
                {
                    break;
                }
            }
            while(!Q.empty())
             {Q.pop();

             }

            printf("%d\n",ans);


        return 0;
    }
