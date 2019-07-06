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
const int lim = 1e5;
int A[lim],rm[lim],ans[lim];
int currentl,currentr;
struct node{
    int l,r,i;
};
node Q[lim];
int bit[lim+1];
int cont ;
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
void addr(int a)
{

    int len = currentr - currentl;
    cont+=(len-query(a-1));
    update(a,1);
}
void remover(int a)
{
    int len = currentr - currentl ;
    cont-=(len-query(a));
    update(a,-1);
}
void removel(int a)
{
    cont-=query(a-1);
    update(a,-1);
}
void addl(int a)
{
    cont+=query(a-1);
    update(a,1);
}
map<int,int> M;
const int block = 300;
inline bool comp(node x,node y)
{
    if( x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

int main()
{
    int n,q;
    scan(n);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        M[A[i]];
    }
    scan(q);
    int maxi = 1;
    for(auto it: M)
    {
        M[it.first] = maxi;
        rm[maxi] = it.first;
        maxi++;
    }
    memset(ans,0,sizeof(ans));
    memset(bit,0,sizeof(bit));
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
    currentr = 0;
    for(int i=0;i<q;++i)
    {
        int l = Q[i].l ;
        int r = Q[i].r;
       // printf("%d %d\n",l,r);
        while(currentr < r+1)
        {
           // cout<<"YS"<<endl;
            addr(M[A[currentr]]);
           // cout<<currentr<<" "<<M[A[currentr]]<<" "<<cont<<endl;

            currentr++;
          //  cout<<currentr<<endl;
        }
        while(currentr > r+1)
        {
            remover(M[A[currentr-1]]);
            currentr--;
           // cout<<currentr<<endl;
        }
        while(currentl < l)
        {
            removel(M[A[currentl]]);
            currentl++;
           // cout<<currentl<<endl;
        }
        while(currentl > l)
        {
            addl(M[A[currentl-1]]);
            currentl--;
           // cout<<currentl<<endl;
        }
        ans[Q[i].i] = cont;

    }
    for(int i=0;i<q;++i)
        cout<<ans[i]<<endl;

    return 0;
}


