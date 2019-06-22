#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6+10;
bool visit[1001][1001];
struct Query
{
    int x,a,b,c,d;
    Query(int x1,int a1 = -1,int b1 = -1,int c1 = -1,int d1 = -1)
    {
        x = x1;
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }
};
vector<Query> Q;
int cellno[1001][1001];
int M1[1001][1001],M2[1001][1001],C1[1001][1001],C2[1001][1001];
int parent[lim],subsize[lim];

int par(int x)
{
    if( parent[x] == -1)
        return x;
    return  (parent[x] = par(parent[x]));
}
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,m;
        scan2(n,m);
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
                visit[i][j] = false,cellno[i][j] = -1,M1[i][j] = 0,M2[i][j]=0,C1[i][j] = 0,C2[i][j] = 0;
      //  M1.clear(),M2.clear();
        int q;
        scan(q);
        int qq = q;
        while(q--)
        {
            int x;
            scan(x);
            if( x == 1)
            {
                int a,b;
                scan2(a,b);
                //cout<<"YO"<<endl;
               // cout<<a<<" "<<b<<endl;
                M1[a][b] = 1;
                C1[a][b]++;
                Q.pb(Query(x,a,b));
            }
            else if( x == 2)
            {
                int a,b;
                scan2(a,b);
                M2[a][b] = 2;
                C2[a][b]++;
                Q.pb(Query(x,a,b));
            }
            else if( x == 3)
            {
                int a,b,c,d;
                scan2(a,b);
                scan2(c,d);
                Q.pb(Query(x,a,b,c,d));
            }
            else
                Q.pb(Query(x));

        }
        int cont = 0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if( visit[i][j] == false)
                {
                    cont++;
                    queue<pii> Qi;
                    Qi.push({i,j});
                    visit[i][j] = true;
                    while(!Qi.empty())
                    {
                        pii tt  = Qi.front();
                        Qi.pop();
                        int x = tt.first;
                        int y = tt.second;
                        cellno[x][y] = cont;
                        //printf("x = %d y = %d m2=  %d m1 = %d\n",x,y,M2[{x,y}],M1[{x,y}]);
                        if( x > 1 && visit[x-1][y] == false && M2[x-1][y] != 2)
                        {
                            Qi.push({x-1,y});
                            visit[x-1][y] = true;
                        }
                        if( y > 1 && visit[x][y-1] == false && M1[x][y-1] != 1)
                        {
                            Qi.push({x,y-1});
                            visit[x][y-1] = true;
                        }
                        if( x < n && M2[x][y] != 2 && visit[x+1][y] == false)
                        {
                            Qi.push({x+1,y});
                            visit[x+1][y] = true;
                        }
                        if( y < m && M1[x][y] != 1 && visit[x][y+1] == false)
                        {
                            Qi.push({x,y+1});
                            visit[x][y+1] = true;
                        }

                    }
                }
            }
        }
        for(int i=0;i<n*m+5;++i)
            parent[i] = -1,subsize[i] = 0;
        int maxi = -1;
        for(int i=1;i<n+1;++i)
        {
            for(int j=1;j<m+1;++j)
             {
               //  cout<<cellno[i][j]<<" ";
                 subsize[cellno[i][j]]++;
                 maxi = max(maxi,subsize[cellno[i][j]]);
             }
          //  cout<<endl;
        }
        reverse(all(Q));
        ll ans  = 0ll;
        for(int i=0;i<qq;++i)
        {
            int x = Q[i].x;
           // printf("par2 = %d par1 = %d\n",parent[2],parent[1]);
            //cout<<ans<<endl;
            if( x == 1)
            {
                int a = Q[i].a;
                int b = Q[i].b;
                if(b+1 > m)
                    continue;
                int fx = par(cellno[a][b]);
                int fy = par(cellno[a][b+1]);
               // cout<<fx<<fy<<endl;
                C1[a][b]--;
                if( C1[a][b] > 0)
                    continue;
                if( fx == fy)
                    continue;
                parent[fy] = fx;
                subsize[fx]+=subsize[fy];
                maxi = max(maxi,subsize[fx]);
            }
            else if( x == 2)
            {
                int a = Q[i].a;
                int b = Q[i].b;
                if( a+1 > n)
                    continue;
                int fx = par(cellno[a][b]);
                int fy = par(cellno[a+1][b]);
              //  cout<<fx<<fy<<endl;
                C2[a][b]--;
                if( C2[a][b] > 0)
                    continue;
                if( fx == fy)
                    continue;
                parent[fy] = fx;
                subsize[fx]+=subsize[fy];
                maxi = max(maxi,subsize[fx]);
            }
            else if( x == 3)
            {
                int a = Q[i].a;
                int b = Q[i].b;
                int c = Q[i].c;
                int d = Q[i].d;
                int fx = par(cellno[a][b]);
                int fy = par(cellno[c][d]);
                if( fx == fy)
                    ans+=(1ll);
            }
            else
                ans+=(1ll*maxi);

          //  cout<<ans<<endl;
        }

        cout<<ans<<endl;
    }
    return 0;
}


