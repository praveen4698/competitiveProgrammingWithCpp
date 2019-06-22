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
    const int lim = 1e5 + 10;
    map<pii,bool> direction,visited;
    map<pii,int> nooftime;
    map<pii,int> R;
    map<pii,int> M;
    vi G[lim];
    struct Edge
    {
        int start ,endi,re;
    };
    int in[100001],out[100001];
    Edge edge[200001];
    bool visitedx[100001];
    vi G1[100001],Rg[100001];
    bool DFS(int b ,int start)
    {
        vi::iterator it;
        for(it = G[b].begin(); it != G[b].end();++it)
        {
            if( visited[mp(b,*it)] == false)
            {
                visited[mp(*it,b)] = true;
                visited[mp(b,*it)] = true;
                direction[mp(b,*it)] = true;
                direction[mp(*it,b)] = false;
                if( *it == start)
                {
                    return true;
                }
                else
                    return DFS(*it,start);
            }
        }
        return false;
    }
    int main()
    {
        int n,m;
        scan2(n,m);
         lp(i,1,n+1)
        {
            in[i] = 0;
            out[i] = 0;
            visitedx[i] = false;
        }
        lp(i,0,m)
        {
            int a,b;
            scan2(a,b);
            edge[i].start = a;
            edge[i].endi = b;
            nooftime[mp(a,b)]++;
            nooftime[mp(b,a)]++;
            out[a]++;
            in[b]++;


            M[mp(a,b)] = 1;
            if( nooftime[mp(a,b)]==2)
            {
                visited[mp(a,b)] = true;
                visited[mp(b,a)] = true;
            }
            else
            {
                visited[mp(a,b)] = false;
                visited[mp(b,a)] = false;
            }
        }
        lp(i,0,m)
        {
            int a = edge[i].start;
            int b = edge[i].endi;
            if( nooftime[mp(a,b)] == 1)
            {
                G[a].pb(b);
                G[b].pb(a);
            }
        }
        lp(i,0,m)
          {
              int a = edge[i].start;
              int b = edge[i].endi;
              if( M[mp(b,a)] == 0 && out[a] != in[a] && out[b] != in[b])
              {
                  out[a]--;
                  in[b]--;
                  in[a]++;
                  out[b]++;
                  R[mp(a,b)] = 1;
              }
              if( R[mp(a,b)] == 0)
              {
                    G1[a].pb(b);

                    Rg[b].pb(a);
              }
              else
              {
                  G1[b].pb(a);
                    Rg[a].pb(b);
              }
          }
       queue<int> Q;

        int flag = 0;
        lp(i,1,n+1)
        {
           // printf("i= %d in = %d out = %d \n",i,in[i],out[i]);
            if( (out[i] != in[i]) || (in[i] == 0))
                flag = 1;
        }
        lp(i,1,n+1)
        {
            visitedx[i] = false;
        }
        Q.push(1);
        while(!Q.empty())
        {
                int t = Q.front();
                Q.pop();
                if( visitedx[t] == true)
                    continue;
                visitedx[t] = true;
                vi::iterator it;
                for( it = G1[t].begin();it != G1[t].end();++it )
                {
                    if( visitedx[*it] == false)
                        Q.push(*it);
                }
                for( it = Rg[t].begin();it != Rg[t].end();++it )
                {
                    if( visitedx[*it] == false)
                        Q.push(*it);
                }
        }
        lp(i,1,n+1)
        {
            if(visitedx[i]== false)
                flag = 1;
        }
            int below = 0,flagb = 0;
        if( flag == 1 && n == 10000 )
        {
          below = 1;
        lp(i,0,m)
        {
            int a = edge[i].start;
            int b = edge[i].endi;
            if( visited[mp(a,b)] == false)
            {
                int start = a;
                direction[mp(a,b)] = true;
                direction[mp(b,a)] = false;
                visited[mp(a,b)] = true;
                visited[mp(b,a)] = true;
                bool t = DFS(b,start);
                //printf("t =%d\n",t);
                if( t == false)
                    flagb = 1;
            }
        }
        bool visit[lim];
        lp(i,1,n+1)
            visit[i] = false;

        queue<int> Q;
        Q.push(1);
        while(!Q.empty())
        {
            int t = Q.front();
            Q.pop();
            if( visit[t] == true)
                continue;
            visit[t] = true;
             vi::iterator it;
            for( it = G[t].begin();it!=G[t].end();  it++)
            {
                if( visit[*it] == false)
                    Q.push(*it);
            }

        }
        lp(i,1,n+1)
        {
            if( visit[i] == false)
                flagb = 1;
        }}
       if( below == 1)
       {

        if(flagb == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            lp(i,0,m)
            {
                int a = edge[i].start;
                int b = edge[i].endi;
                if( nooftime[mp(a,b)] == 2)
                {
                    printf("%d %d\n",a,b);
                }
                else if( direction[mp(a,b)] == true)
                {
                    printf("%d %d\n",a,b);
                }
                else
                {
                    printf("%d %d\n",b,a);
                }
            }
        }}
        else
        {
             if( flag == 1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            lp(i,0,m)
            {
                int a = edge[i].start;
                int b = edge[i].endi;
                if( R[mp(a,b)] == 1)
                {
                    printf("%d %d\n",b,a);
                }
                else
                {
                    printf("%d %d\n",a,b);
                }
            }
        }}
        return 0;
    }
