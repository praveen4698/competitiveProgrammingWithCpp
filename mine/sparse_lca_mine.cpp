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
const int lim = 1e5 + 10;
const int logn = 20;
int sparse_table[lim<<4][logn],sparse_level[lim],pos_in_tree[lim];// for lca
int sparse_index[lim<<4][logn];
int sparse_k[lim<<4];
vector<int> G[lim] ; // store graph
vector<int> tree_traversal;
void dfs_sparse(int ver,int depth,int par=-1)
{
    tree_traversal.push_back(ver);
    pos_in_tree[ver] = tree_traversal.size() -1;
    sparse_level[ver] = depth;
    for(int child:G[ver])
    {
        if( child == par)
            continue;
        dfs_sparse(child,depth+1,ver);
        tree_traversal.push_back(ver);
    }
    pos_in_tree[ver] = tree_traversal.size()-1;
}
void preprocess_sparse()
{
    dfs_sparse(0,0);
    int n = tree_traversal.size();
    for(int i=0;i<n;++i)
    {
        sparse_table[i][0] = sparse_level[tree_traversal[i]];
        sparse_index[i][0] = tree_traversal[i];
    }
    int k =2 ;
    sparse_k[1] = 0;
    sparse_k[2] =1;
    int j = 1;
    for(int i=3;i<lim<<4;++i)
    {
        if( i == 2*k)
            k = 2*k,j++;
        sparse_k[i] = j;
    }
    for(int k=1;k<logn;++k)
    {
        if( 1<<k >= n)
            continue;
        for(int i=0;i<n;++i)
        {
            int x = i+(1<<(k-1));
            if( sparse_table[i][k-1] < sparse_table[x][k-1])
            {
                sparse_table[i][k] = sparse_table[i][k-1];
                sparse_index[i][k] = sparse_index[i][k-1];
            }
            else
            {
                sparse_table[i][k] = sparse_table[x][k-1];
                sparse_index[i][k] = sparse_index[x][k-1];
            }
        }
    }
}
int lca_sparse(int a,int b)
{
    int fa = pos_in_tree[a];
    int fb = pos_in_tree[b];
    if( fb < fa )
        swap(fb,fa);
    int k = sparse_k[fb-fa+1];
    int j = fb - (1<<k) + 1;
    if( sparse_table[fa][k] < sparse_table[j][k])
        return sparse_index[fa][k];
    else
        return sparse_index[j][k];

}
int dp[lim][logn],level[lim],sub[lim],par[lim];
void DFS0(int u)
{
    for(auto it:G[u])
    {
        if(dp[u][0] != it)
        {
            dp[it][0] = u;
            level[it] = level[u] + 1;
            DFS0(it);
        }
    }
}
void preprocess(int n)
{
    dp[0][0] = 0;
    level[0] = 0;
    DFS0(0);
    for(int j=1;j<logn;++j)
    {
        for(int i=0;i<n;++i)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}
int lca(int a,int b)
{
    if(level[b] < level[a])
        swap(a,b);
    int d = level[b] - level[a];
    for(int i=0;i<logn;++i)
        if(d&(1<<i))
            b = dp[b][i];

    if( a== b) return b;

    for(int i=logn-1;i>=0;i--)
    {
        if(dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        scan2(a,b);
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);

    }
    preprocess_sparse();
    //for(auto a:tree_traversal)
    //     cout<<a<<endl;
    int q;
    scan(q);
    while(q--)
    {
        int a,b;
        scan2(a,b);
        cout<<lca_sparse(a-1,b-1)+1<<endl;
    }
    return 0;
}


