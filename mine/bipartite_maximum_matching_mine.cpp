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
// 1 base indexing
// O( E*sqrt(v))
// may be some fault

const int lim = 1e5+10;
int match[lim],dist[lim];
vector<int> G[lim];
bool BFS(int n){
    
    queue<int> Q;
    for(int i=1;i<=n;++i){
        
        if( match[i] == 0){
            
            Q.push(i);
            dist[i] = 0;
        }
        else
            dist[i] = INF;
    }
    
    dist[0] = INF;
    while(!Q.empty()){
        
        int ver = Q.front();
        Q.pop();
        if( ver > 0)
        {
            for(int child:G[ver])
            {
                if( dist[match[child]] == INF )
                {
                    dist[match[child]] = dist[ver]+1;
                    Q.push(match[child]);
                }
            }
        }
    }
    return dist[0] < INF;
}
bool DFS(int ver)
{
    if( ver > 0)
    {
        for(int child:G[ver])
        {
            if( dist[match[child]] == dist[ver]+1 && DFS(match[child]))
            {
                match[child] = ver;
                match[ver] = child;
                return true;
            }
        }
        dist[ver] = INF;
        return false;
    }
    return true;
}
int matching(int n)
{
    int ans = 0;
    for(int i=0;i<=n;++i)
        match[i] = 0;
    while(BFS(n))
    {
        for(int i=1;i<=n;++i)
        {
            if( match[i] == 0 && DFS(i))
                ans++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}


