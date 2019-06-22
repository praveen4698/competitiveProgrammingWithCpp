#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    int prime[lim];
    int A[lim];
    void seive()
    {
        for(int i=0;i<lim;++i)
            prime[i] = 1;
        prime[0] = 0;
        prime[1] = 0;
        for(int i=2;i<lim;++i)
        {
            if(prime[i] == 1)
            {
                for(int j=2*i;j<lim;j = j+i)
                {
                    prime[j] = 0;
                }
            }

        }

    }
    struct TNode
    {
        int l,r ;
        int sum ;
        int up;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            sum = value;
            up = 0;
        }

        void merge(TNode& left, TNode& right)
        {
            sum = left.sum + right.sum;
            up = 0;
        }

    };
    TNode nodes[800000];
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               // printf("%d \n",prime[A[lo]]);
               nodes[st].assignLeaf(prime[A[lo]]);
               return ;
        }
        int mid = (lo + hi)/2;
        buildTree(st*2,lo,mid);
        buildTree(st*2+1,mid+1,hi);
        nodes[st].merge(nodes[st*2],nodes[st*2+1]);
    }
        TNode query(int st,int lo,int hi)
    {
        if( nodes[st].up != 0)
        {
            if( nodes[st].up == -1)
                nodes[st].sum = 0;
            else
                nodes[st].sum = nodes[st].r - nodes[st].l + 1;
            if(nodes[st].l != nodes[st].r)
            {
                nodes[2*st].up = nodes[st].up;
                nodes[2*st+1].up = nodes[st].up;
            }
            nodes[st].up= 0;

        }
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            TNode res = nodes[st];
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        TNode res;
        if( lo > mid)
            res = query(2*st+1,lo,hi);
        else if( hi <= mid)
            res = query(2*st,lo,hi);
        else
        {
            TNode lr = query(2*st, lo, mid);
            TNode rr = query(2*st+1, mid+1, hi);
            res.l = lr.l;
            res.r = rr.r;
            res.merge(lr, rr);
        }
		return res;

    }
        void update2(int st, int lo, int hi,int value)
        {
            if( nodes[st].up != 0)
            {
                if( nodes[st].up == -1)
                    nodes[st].sum = 0;
                else
                    nodes[st].sum = nodes[st].r - nodes[st].l + 1;
                if(nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up = nodes[st].up;
                    nodes[2*st+1].up = nodes[st].up;
                }
                nodes[st].up= 0;

            }
            if (nodes[st].l == lo && nodes[st].r == hi)
            {
                if( value == -1)
                    nodes[st].sum = 0;
                else
                    nodes[st].sum = nodes[st].r - nodes[st].l + 1;
                if(nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up = value;
                    nodes[2*st+1].up = value;
                }
                nodes[st].up= 0;
                return;
            }

            int mid = (nodes[st].l + nodes[st].r) / 2;
            if (lo > mid)
                update2(2*st+1,lo,hi, value);
            else if (hi <= mid)
                update2(2*st,lo,hi, value);
            else
            {
                update2(2*st ,lo, mid, value);
                update2(2*st+1,mid+1,hi, value);
            }
            nodes[st].merge(nodes[2*st], nodes[2*st+1]);
        }
    int main()
    {
        int t;
        scanf("%d",&t);
        int x = 1;
        seive();
        while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            for(int i=0;i<n;++i)
                scanf("%d",&A[i]);
            buildTree(1,0,n-1);

            printf("Case %d:\n",x);
            x++;
            while(m--)
            {
                int a;
                scanf("%d",&a);
                if(a == 0)
                {
                    int b,c,d;
                    scanf("%d %d %d",&b,&c,&d);
                    int value = prime[d];
                    if(value == 0)
                        value = -1;
                    update2(1,b-1,c-1,value);
                }
                else
                {
                    int b,c;
                    scanf("%d %d",&b,&c);
                    TNode ans = query(1,b-1,c-1);
                    printf("%d\n",ans.sum);
                }
            }
        }

        return 0;
    }

