#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int M[50001],m;
    bool visited[50001];
    vpii G[50001];
    struct Edge
    {
        int start,end ,weight;
    };
    Edge edge[100001];
    map<pair<int,int>,int> A;
    int BFS(int a,int b)
    {
        visited[a] = true;
        visited[b] = true;
        int temp = 0;
        vpii::iterator i;
        for(i = G[b].begin();i != G[b].end();++i)
        {
            if( visited[(*i).first] == false)
            {
                A[mp(b,(*i).first)] = BFS(b,(*i).first);
                temp = temp + M[(*i).first] + A[mp(b,(*i).first)];
               // printf("A[%d,%d] = %d\n",b,(*i).first,A[mp(b,(*i).first)]);
                A[mp((*i).first,b)] = m - A[mp(b,(*i).first)] - M[b] - M[(*i).first] ;
               // visited[(*i).first] = true;
            }
        }
        return temp;
    }
    int main()
    {
        int Z;
        scan(Z);
        while(Z--)
        {
            int n;
            scan(n);
            scan(m);
            lp(i,0,50001)
            {
                visited[i] = false;
                M[i] = 0;
            }
            int j = 0;
            lp(i,0,n-1)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                G[a].pb(mp(b,c));
                G[b].pb(mp(a,c));
                edge[i].start = a;
                edge[i].end = b;
                edge[i].weight = c;

            }
            lp(i,0,m)
            {
                int a;
                scan(a);
                M[a] = 1;
            }
            A[make_pair(edge[0].start,edge[0].end)] =  BFS(edge[0].start,edge[0].end);
            lp(i,0,n)
            {
                visited[i] = false;
            }
            A[make_pair(edge[0].end,edge[0].start)] =  BFS(edge[0].end,edge[0].start);

            long long int sum = 0;
            lp(i,0,n-1)
            {
                long long int temp = ( (long long int)A[mp(edge[i].start,edge[i].end)] + M[edge[i].end])*( (long long int)A[mp(edge[i].end,edge[i].start)] + M[edge[i].start]);
               // printf("\n\n A[%d,%d] = %d\n ",edge[i].start,edge[i].end,A[mp(edge[i].start,edge[i].end)]);
               // printf("A[%d,%d] = %d\n\n ",edge[i].end,edge[i].start,A[mp(edge[i].end,edge[i].start)]);
                temp = (long long int)temp*2*edge[i].weight;
                sum = (long long int)sum + temp;
            }
            long long int demon = (long long int)m*m;
            //printf("%lld %lld\n",sum,demon);
            lpr(i,50001,2)
            {
                while(sum%i == 0 && demon%i == 0)
                {
                    sum = sum/i;
                    demon = demon/i;
                }
                //if( i > demon)
                //    break;
            }
            printf("%lld %lld\n",sum,demon);
            //lp(i,0,50000)
            lp(i,0,50001)
            {

                G[i].clear();
            }
            A.clear();

        }
        return 0;
    }

