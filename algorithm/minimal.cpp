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
const int lim = 1e6+10;
struct TNode
{
    int l,r ;
    int mini ,up;
    TNode() : l(0), r(0) {};// constructor

    void assignLeaf(int value)
    {
        mini = value;
        up = 0;

    }

    void merge(TNode& left, TNode& right)
    {
        up = 0;
        mini = min(left.mini,right.mini);
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
            nodes[st].assignLeaf(A[lo]);
            return ;
    }
    int mid = (lo + hi)>>1;
    buildTree(st<<1,lo,mid);
    buildTree(st<<1|1,mid+1,hi);
    nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
}
void lazy(int st)
{
    nodes[st].mini+=nodes[st].up;
    if( nodes[st].l != nodes[st].r)
    {
        nodes[2*st].up+=nodes[st].up;
        nodes[2*st+1].up+=nodes[st].up;
    }
    nodes[st].up = 0;
}
int querylazy(int st,int lo,int hi)
{

    lazy(st);
    if(nodes[st].l > hi || nodes[st].r < lo)
        return INF;

    if( nodes[st].l >= lo && nodes[st].r <= hi)
        return nodes[st].mini;

    return min(querylazy(2*st,lo,hi),querylazy(2*st+1,lo,hi));
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
char w[100];
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
        scan(A[i]);
    buildTree(1,0,n-1);
    int q;
    scan(q);
    gets(w);
    while(q--)
    {
        gets(w);
        stringstream in(w);
        int a,b,c;
        in>>a>>b;
        if( in>>c)
        {
            if( a > b)
            {
                updatelazy(1,a,n-1,c);
                updatelazy(1,0,b,c);
            }
            else
                updatelazy(1,a,b,c);
        }
        else
        {
            if( a>b)
            {
                cout<<min(querylazy(1,a,n-1),querylazy(1,0,b));
            }
            else
                cout<<querylazy(1,a,b);
            cout<<endl;
        }
    }
    return 0;
}


