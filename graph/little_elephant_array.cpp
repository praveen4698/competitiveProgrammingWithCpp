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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5+10;
int A[lim];
ll ans[lim];
int currentl,currentr;
struct node{
    int l,r,i;
};
node Q[lim];
ll cont ;
int M[lim*10];
inline void addr(int a)
{

    cont  = cont - 1ll*(M[a])*(M[a])*a + 1ll*(M[a]+1)*1ll*(M[a]+1)*1ll*a;
    M[a]++;
}
inline void remover(int a)
{
    //int len = currentr - currentl ;
    cont = cont - 1ll*(M[a])*(M[a])*a + 1ll*(M[a]-1)*1ll*(M[a]-1)*1ll*a;
    M[a]--;
}
inline void removel(int a)
{
    M[a]--;
    if( M[a] == a)
        cont++;
    else if( M[a] == a-1)
        cont--;
}
inline void addl(int a)
{
    M[a]++;
    if( M[a] == a)
        cont++;
    if( M[a] == a+1)
        cont--;
}
//map<int,int> M;
const int block = 800;
inline bool comp(node x,node y)
{
    if( x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

int main()
{
    int n,q;
    scan2(n,q);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        M[A[i]] = 0;
    }
    memset(ans,0ll,sizeof(ans));
   // memset(bit,0,sizeof(bit));
    for(int i=0;i<q;++i)
    {
        Q[i].i = i;
        int a,b;
        scan2(a,b);
        Q[i].l = a-1;
        Q[i].r = b-1;
    }
    sort(Q,Q+q,comp);
    cont = 0;
    currentl = 0;
    currentr = -1;
    for(int i=0;i<q;++i)
    {
        int l = Q[i].l ;
        int r = Q[i].r;
       // printf("%d %d\n",l,r);
        while(currentr < r)
        {
           // cout<<"YS"<<endl;
            addr(A[currentr+1]);
           // cout<<currentr<<" "<<M[A[currentr]]<<" "<<cont<<endl;

            currentr++;
          //  cout<<currentr<<endl;
        }
        while(currentr > r)
        {
            remover(A[currentr]);
            currentr--;
           // cout<<currentr<<endl;
        }
        while(currentl < l)
        {
            remover(A[currentl]);

            currentl++;
           // cout<<currentl<<endl;
        }
        while(currentl > l)
        {
            addr(A[currentl-1]);
            currentl--;
        }
        ans[Q[i].i] = 1ll*cont;

    }
    for(int i=0;i<q;++i)
        cout<<ans[i]<<endl;

    return 0;
}


