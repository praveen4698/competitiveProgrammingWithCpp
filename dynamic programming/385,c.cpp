#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vi G[1001];
    int K[1001];
    bool visited[1001];
    int main()
    {
        int n,k,m;
        scan3(n,m,k);
        lp(i,0,k)
            scan(K[i]);
        lp(i,0,m)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        lp(i,0,n+1)
            visited[i] = false;
        queue<int> Q;
        int maxi = -1;
        int cont = 0;
        lp(i,0,k)
        {
            Q.push(K[i]);
            int temp = 0;
            while( !Q.empty())
            {
                int t = Q.front();
                Q.pop();
                if( visited[t] == true)
                    continue;
                visited[t] = true;
                temp++;
                vi::iterator it;
                for(it = G[t].begin();it != G[t].end(); ++it)
                {
                    if( visited[*it] == false)
                        Q.push(*it);
                }
            }
            cont = cont + ((temp)*(temp-1))/2;
            maxi = max(maxi,temp);
        }

        int temp = 0;
        lp(i,1,n+1)
        {
            if( visited[i] == false)
                temp++;
        }
        cont = cont + (temp*(2*maxi + temp - 1))/2;
        printf("%d",cont - m);
        return 0;
    }
