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
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 1e7 + 10;
const int logn = 35;
int sparse_table[logn][lim];//sparse_level[lim],pos_in_tree[lim];// for lca
//int sparse_index[lim][logn];
int sparse_k[lim];
//vector<int> G[lim] ; // store graph
//v/ector<int> tree_traversal;
ll input[lim];
//int n,k,q;
void preprocess_sparse(int n)
{
   // dfs_sparse(0,0);
    //int n = tree_traversal.size();
    for(int i=0;i<n;++i)
    {
        sparse_table[0][i] = input[i];
        //sparse_index[i][0] = tree_traversal[i];
    }
    int k =2 ;
    sparse_k[1] = 0;
    sparse_k[2] =1;
    int j = 1;
    for(int i=3;i<lim;++i)
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
            if( sparse_table[k-1][i] < sparse_table[k-1][x])
            {
                sparse_table[k][i] = sparse_table[k-1][i];
                //sparse_index[i][k] = sparse_index[i][k-1];
            }
            else
            {
                sparse_table[k][i] = sparse_table[k-1][x];
                //sparse_index[i][k] = sparse_index[x][k-1];
            }
        }
    }
}
int lca_sparse(int a,int b)
{
    int fa = a;
    int fb = b;
    if( fb < fa )
        swap(fb,fa);
    int k = sparse_k[fb-fa+1];
    //int k = log2(fb-fa+1);
    int j = fb - (1<<k) + 1;
    if( sparse_table[k][fa] < sparse_table[k][j])
        return sparse_table[k][fa];
    else
        return sparse_table[k][j];

}
int main()
{
    //memset(sparse_table,0,sizeof(sparse_table));
    int n,K,queries ;
    scanf("%d %d %d",&n,&K,&queries) ;
    ll a, b, c, d, e, f, r, s, t, m ;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&input[0]) ;
    ll temp=t%s ;
    for(ll i=1  ; i<n ; i++) {
        temp=((temp%s)*(t%s))%s ;
        if(temp<=r) {
            input[i]= (a*input[i-1]*input[i-1] + b*input[i-1] + c)%m ;
        }
        else {
            input[i]= (d*input[i-1]*input[i-1] + e*input[i-1] + f)%m ;
        }
    }

    preprocess_sparse(n) ;
    //print(n) ;
    ll L1, La, Lc, Lm, D1, Da, Dc, Dm,L,R,sum=0,pro=1 ;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm) ;
    while(queries--) {
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        L = L1 + 1;
        R = (L+K-1+D1)<n ? (L+K-1+D1) : n ;

        ll temp = 1ll*lca_sparse(L-1,R-1);
        sum+=temp;
        pro*=temp;
        pro%=mod;
        /*int k=31-__builtin_clz(R-L+1);
        int temp= (input[sparseTable[k][L-1]]<=input[sparseTable[k][R-(1<<k)]]) ? input[sparseTable[k][L-1]] : input[sparseTable[k][R-(1<<k)]] ;
        sum+=temp ;
        pro*=temp ;
        if(pro>=MOD) {
            pro%=MOD ;
        }*/
    }
    printf("%lld %lld\n",sum,pro);


    return 0;
}


