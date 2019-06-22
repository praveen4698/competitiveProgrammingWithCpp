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

    map<pii,int> R;
    map<pii,int> M;
    int in[100001],out[100001];
    struct Edge
    {
        int start,endi;
    };
    Edge edge[200001];
    vi G[100001],Rg[100001];
    int main()
    {
        bool visited[100001];
        int n,m;
        scan2(n,m);
        lp(i,1,n+1)
        {
            in[i] = 0;
            out[i] = 0;
            visited[i] = false;
        }
        lp(i,0,m)
        {
            int a,b;
            scan2(a,b);
            out[a]++;
            in[b]++;
            edge[i].start = a;
            edge[i].endi = b;
            G[a].pb(b);

            Rg[b].pb(a);
            M[mp(a,b)] = 1;
        }
      /*  lp(i,0,m)
          {
              int a = edge[i].start;
              int b = edge[i].endi;
              if(M[mp(b,a)] == 0 && (in[a] == out[a]))
              {
                  out[a]--;
                  in[b]--;
                  in[a]++;
                  out[b]++;
                  R[mp(a,b)] = 1;
              }

          }*/
        lp(i,0,m)
          {
              int a,b;
               a = edge[i].start;
                b = edge[i].endi;
              if( M[mp(b,a)] == 0 && out[a] != in[a] && out[b] != in[b])
              {



                  out[a]--;
                  in[b]--;
                  in[a]++;
                  out[b]++;
                  R[mp(a,b)] = 1;



              }
         /*     if( R[mp(a,b)] == 0)
              {
                    G[a].pb(b);

                    Rg[b].pb(a);
              }
              else
              {
                    G[b].pb(a);
                    Rg[a].pb(b);
              }*/
          }
       queue<int> Q;
       /*
        lp(i,1,n+1)
        {
            if(out[i] != in[i])
            {
                Q.push(i);
            }
        }

      /*  while(!Q.empty())
        {
            int t = Q.front();
            Q.pop();
           // printf("Q = %d\n",t);
            if(visited[t] == true)
                continue;

            visited[t] = true;
            if( out[t] > in[t])
            {
                vi::iterator it;
                for( it = G[t].begin();it != G[t].end();++it )
                {
                    int a = t;
                    int b = *it;
                    if( M[mp(b,a)] == 0 && visited[b] == false)
                    {

                        R[mp(a,b)] = 1 - R[mp(a,b)];
                        out[a]--;
                        in[b]--;
                        in[a]++;
                        out[b]++;
                        if( out[b] != in[b])
                        {
                            Q.push(b);
                        }
                        if( out[a] <= in[a])
                            break;
                    }
                }
            }
            if( in[t] > out[t])
            {
                vi::iterator it;
                for( it = Rg[t].begin();it != Rg[t].end();++it )
                {
                    int b = t;
                    int a = *it;
                    if( M[mp(b,a)] == 0 && visited[a] == false)
                    {
                        R[mp(a,b)] = 1 - R[mp(a,b)];
                        out[a]--;
                        in[b]--;
                        in[a]++;
                        out[b]++;
                        if( out[a] != in[a])
                        {
                            Q.push(b);
                        }
                        if( out[b] >= in[b])
                            break;
                    }
                }
            }
        }
        */
        int flag = 0;
        lp(i,1,n+1)
        {
           // printf("i= %d in = %d out = %d \n",i,in[i],out[i]);
            if( (out[i] != in[i]) || (in[i] == 0))
                flag = 1;
        }
        lp(i,1,n+1)
        {
            visited[i] = false;
        }
        Q.push(1);
        while(!Q.empty())
        {
                int t = Q.front();
                Q.pop();
                if( visited[t] == true)
                    continue;
                visited[t] = true;
                vi::iterator it;
                for( it = G[t].begin();it != G[t].end();++it )
                {
                    if( visited[*it] == false)
                        Q.push(*it);
                }
                for( it = Rg[t].begin();it != Rg[t].end();++it )
                {
                    if( visited[*it] == false)
                        Q.push(*it);
                }
        }
        lp(i,1,n+1)
        {
            if(visited[i]== false)
                flag = 1;
        }
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
        }
        return 0;
    }
