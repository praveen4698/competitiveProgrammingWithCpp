#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
struct TNode
{
    int l,r ;
    ll mini ,up,sum;
    TNode() : l(0), r(0) {};// constructor

    void assignLeaf(ll value)
    {
        mini = value;
        sum = value;
        up = 0;

    }

    void merge(TNode& left, TNode& right)
    {
        up = 0;
        mini = min(left.mini,right.mini);
        sum = left.sum + right.sum;
    }

};
TNode nodes[800000];
int A[lim];
void buildTree(int st,int lo,int hi)
{
    nodes[st].l = lo;
    nodes[st].r = hi ;
    if(lo == hi)
    {
            nodes[st].assignLeaf(1ll*INF);
            return ;
    }
    int mid = (lo + hi)>>1;
    buildTree(st<<1,lo,mid);
    buildTree(st<<1|1,mid+1,hi);
    nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
}
void lazy(int st)
{
    nodes[st].mini-=nodes[st].up;
    if( nodes[st].l != nodes[st].r)
    {
        nodes[2*st].up+=nodes[st].up;
        nodes[2*st+1].up+=nodes[st].up;
    }
    nodes[st].sum = (nodes[st].r-nodes[st].l+1)*1ll*nodes[st].up;
    nodes[st].up = 0;
}
ll querylazy(int st,int lo,int hi,ll value)
{

    lazy(st);
    if(nodes[st].l > hi || nodes[st].r < lo)
        return 0;
    if(nodes[st].sum == 0 )
        return 0;
    if( nodes[st].l >= lo && nodes[st].r <= hi && nodes[st].mini > value)
    {
        nodes[st].up+=value;
        return (nodes[st].r-nodes[st].l+1)*1ll*value;
    }
    if( nodes[st].l == nodes[st].r )
    {
        ll ans = nodes[st].mini;
        nodes[st].mini = INF;
        nodes[st].sum = 0ll;
        return ans;
    }
    ll ans1 = querylazy(2*st,lo,hi,value);
    ll ans2 = querylazy(2*st+1,lo,hi,value);
    lazy(2*st);
    lazy(2*st+1);
    nodes[st].merge(nodes[2*st],nodes[2*st+1]);
    return ans1+ans2;
}
void updatelazy(int st, int lo, int hi,int value)
{
    lazy(st);
    if( hi < nodes[st].l || lo > nodes[st].r)
            return ;
    if( (nodes[st].l >= lo) && (hi >= nodes[st].r))
    {
        nodes[st].up +=value;
        lazy(st);
        return ;
    }

    updatelazy(2*st,lo,hi,value);
    updatelazy(2*st+1,lo,hi,value);
    nodes[st].merge(nodes[2*st],nodes[2*st+1]);
}

int main()
{
    return 0;
}


