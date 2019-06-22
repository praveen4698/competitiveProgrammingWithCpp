#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
// #include<sys/resource.h>
// void enlargeStack ()
// {
//     struct rlimit lim;
//     getrlimit(RLIMIT_STACK, &lim);
//     lim.rlim_cur = lim.rlim_max;
//     setrlimit(RLIMIT_STACK, &lim);
// }
const int lim = 1e6+10;
const int logn = 25;

vector<int> G[lim];
int par[lim][logn] ;
int P[lim];
int ans[lim];
int temp[lim];
void DFS(int ver,int value, int temp){

    ans[ver] = temp;
    if( P[ver] > value){
        value = P[ver];
        ans[ver] = temp+1;
    }

    for(auto i:G[ver]){
        par[i][0] = ver;
        DFS(i,value,ans[ver]);
    }
     return;

}
int main()
{
    // enlargeStack();
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        for(int i=1;i<n+1;++i){
            G[i].clear();
            ans[i] = -1;
        }
            // G[i].clear();
        for(int i=1;i<n+1;++i)
            scan(P[i]);

        for(int i=2;i<n+1;++i){
            int a;
            scan(a);
            G[a].push_back(i);
            // G[i].pb(a);
        }
        par[1][0] = 1;
        temp[1] = P[0];
        ans[1] = 1;
       // DFS(1,0,0);
        for(int i=1;i<n+1;++i){
            for(auto j: G[i]){
                if( P[j] > temp[i]){
                    ans[j] = ans[i]+1;
                    temp[j] = P[j];
                }
                else{
                    ans[j] = ans[i];
                    temp[j] = temp[i];
                }
                par[j][0] = i;
            }
        }
        for(int j=1;j<logn;++j){
            for(int i=1;i<n+1;++i){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }

        int q;
        scan(q);
        int prev = 0;
        while(q--){
            int v,w;
            scan2(v,w);
            v = v^prev;
            w = w^prev;
           // printf("%d %d \n",v,w);
            int ver = -1;
            int tt = v;
            for(int i = logn-1;i>= 0 ;--i){
                if(P[par[v][i]] > w){
                    v = par[v][i];
                }
            }
           // cout<<v<<endl;
            int ret = 0 ;
            if( P[1] > w){
                ret = ans[tt];
            }
            else if( P[tt] >= w)
            {
                ret = 1;
            }
            else
            {
                ret = ans[tt] - ans[v];
            }
            if( P[v] > w)
                ret++;
            prev =ret;

            cout<<ret<<endl;
        }


    }

    return 0;
}

