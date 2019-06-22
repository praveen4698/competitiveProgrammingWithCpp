#include<bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    struct TNode
    {
        int l,r ;
        int pc,sc,p,s,maxi;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            maxi = pc = sc = 1;
            p = s = value;
        }

        void merge(TNode& left, TNode& right)
        {
            maxi = max(left.maxi,right.maxi);
            if(left.s == right.p)
            {
                maxi = max(maxi,left.sc+right.pc);
            }
            if(left.p == right.p)
            {
                pc = left.pc+right.pc;
                p = left.p;
            }
            else
            {
                pc = left.pc;
                p = left.p;
            }
            if(left.s == right.s)
            {
                sc = left.sc + right.sc;
                s = left.s;
            }
            else
            {
                sc = right.sc;
                s = right.s;
            }
        }

    };
    TNode nodes[800000];
    int A[100001];
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(A[lo]);
               return ;
        }
        int mid = (lo + hi)/2;
        buildTree(st*2,lo,mid);
        buildTree(st*2+1,mid+1,hi);
        nodes[st].merge(nodes[st*2],nodes[st*2+1]);
    }
        TNode query(int st,int lo,int hi)
    {

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
    int main()
    {
        while(1)
        {
            int n,m;
            scanf("%d",&n);
            if(n == 0)
                return 0;
            scanf("%d",&m);
            for(int i=0;i<n;++i)
                scanf("%d",&A[i]);
            buildTree(1,0,n-1);
            while(m--)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                a--;
                b--;
                printf("%d\n",query(1,a,b).maxi);
            }
        }
        return 0;
    }
