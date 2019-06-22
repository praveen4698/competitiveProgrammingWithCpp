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
    const int lim = 1e5;
    vi A[lim];
    int dist[lim];
    bool visited[lim];
    int n;
    void BFS(int s)
    {
        lp(i,1,n+1)
            dist[i] = INF;
        queue<int> Q;
        Q.push(s);
        dist[s] = 0;
        while(!Q.empty())
        {
            int f = Q.front();
            Q.pop();
            vi::iterator i;
            visited[f] = true;
            for(i = A[f].begin();i != A[f].end();++i)
            {
                if( visited[*i] == false &&  dist[*i] > dist[f]+1)
                {
                    dist[*i] = dist[f] +1;
                    Q.push(*i);
                }
            }

        }
    }

    int main()
    {
         scan(n);
         lp(i,1,n+1)
         {
             visited[i] = false;
         }
         lp(i,1,n)
         {
             int a,b;
             scan2(a,b);
             A[a].pb(b);
             A[b].pb(a);
         }
         BFS(1);
         int maxi = 0,s;
         lp(i,1,n+1)
         {
             if(dist[i] == INF)
                continue;
             if( dist[i] > maxi )
             {
                 maxi = dist[i];
                 s = i;
             }
         }
       //  printf("%d ",s);
         lp(i,1,n+1)
         {
             visited[i] = false;
         }
         BFS(s);
         maxi = 0;
         lp(i,1,n+1)
         {
             if( dist[i] == INF)
                continue;
             if( dist[i] > maxi)
                maxi = dist[i];
         }
         printf("%d\n",maxi);
        return 0;
    }

