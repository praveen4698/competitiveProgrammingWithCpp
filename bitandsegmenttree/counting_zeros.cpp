#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5+10;
    struct TNode
    {
        int l,r ;
        int five,two,upfive,uptwo,up;
        TNode() : l(0), r(0),five(0),two(0),upfive(0),uptwo(0),up(0) {};// constructor

        void assignLeaf(int value)
        {
            while(value%2 == 0)
            {
                value/=2;
                two++;
            }
            while(value%5 ==0)
            {
                value/=5;
                five++;
            }
            //printf("%d %d\n",two,five);
        }

        void merge(TNode& left, TNode& right)
        {
            two = left.two+right.two;
            five = left.five+right.five;
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
    void updatelazy(int st, int lo, int hi,int two,int five)
    {
        if( nodes[st].up > 0)
        {

            nodes[st].two = (nodes[st].r-nodes[st].l+1)*nodes[st].uptwo;
            nodes[st].five = (nodes[st].r-nodes[st].l+1)*nodes[st].upfive;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].up = nodes[st].up;
                nodes[2*st+1].up =  nodes[st].up;
                nodes[2*st].uptwo = nodes[st].uptwo;
                nodes[2*st].upfive = nodes[st].upfive;
                nodes[2*st+1].uptwo = nodes[st].uptwo;
                nodes[2*st+1].upfive = nodes[st].upfive;
            }
            nodes[st].up = 0;
        }

        if( hi < nodes[st].l || lo > nodes[st].r)
                return ;
        if( (nodes[st].l >= lo) && (hi >= nodes[st].r))
        {


            nodes[st].two = (nodes[st].r-nodes[st].l+1)*two;
            nodes[st].five = (nodes[st].r-nodes[st].l+1)*five;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].up = 1;
                nodes[2*st+1].up =  1;
                nodes[2*st].uptwo = two;
                nodes[2*st].upfive = five;
                nodes[2*st+1].uptwo = two;
                nodes[2*st+1].upfive = five;
            }
            nodes[st].up = 0;
            return ;
        }

        updatelazy(2*st,lo,hi,two,five);
        updatelazy(2*st+1,lo,hi,two,five);
        nodes[st].merge(nodes[2*st],nodes[2*st+1]);
    }
    pair<int,int>  query(int st, int lo, int hi)
    {
        if( nodes[st].up > 0)
        {

            nodes[st].two = (nodes[st].r-nodes[st].l+1)*nodes[st].uptwo;
            nodes[st].five = (nodes[st].r-nodes[st].l+1)*nodes[st].upfive;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].up = nodes[st].up;
                nodes[2*st+1].up =  nodes[st].up;
                nodes[2*st].uptwo = nodes[st].uptwo;
                nodes[2*st].upfive = nodes[st].upfive;
                nodes[2*st+1].uptwo = nodes[st].uptwo;
                nodes[2*st+1].upfive = nodes[st].upfive;
            }
            nodes[st].up = 0;
        }

        if( hi < nodes[st].l || lo > nodes[st].r)
                return {0,0};
        if( (nodes[st].l >= lo) && (hi >= nodes[st].r))
        {
            return {nodes[st].two,nodes[st].five};
        }

        pair<int,int> ans1 = query(2*st,lo,hi);
        pair<int,int> ans2 = query(2*st+1,lo,hi);
        return {ans1.first+ans2.first,ans1.second+ans2.second};

    }
    inline int readint()
    {
        int x=0,f=1;
        char ch=getchar();
        while(ch<'0'||ch>'9')
        {
            if(ch=='-')
                f = -1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9')
        {
            x=x*10+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    int main()
    {
        int n;
        //scanf("%d",&n);
        n = readint();
        for(int i=0;i<n;++i)
            A[i] = readint();
        buildTree(1,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b,c;
            //scanf("%d %d %d",&a,&b,&c);
            a = readint();
            b = readint();
            c = readint();
            if(a == 1)
            {
                pair<int,int> ans = query(1,b-1,c-1);
                printf("%d\n",min(ans.first,ans.second));
            }
            else
            {
                int d;
                d = readint();
                int two = 0;
                int five = 0;
                while(d%2==0)
                    d/=2,two++;
                while(d%5==0)
                    d/=5,five++;
                updatelazy(1,b-1,c-1,two,five);
            }
        }
        return 0;
    }
