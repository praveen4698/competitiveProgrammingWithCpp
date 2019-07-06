#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    struct TNode
    {
        int l,r ;
        int maxi,open,closed;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(char value)
        {
            maxi = 0;
            open = 0;
            closed = 0;
            if( value == '(')
                open++;
            else
                closed++;
        }

        void merge(TNode& left, TNode& right)
        {
            int t = min(left.open,right.closed);
            maxi = left.maxi + right.maxi + t;
            open = left.open + right.open - t;
            closed = left.closed + right.closed - t;
        }

    };
    TNode nodes[8000000];
    char A[1000001];
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
        scanf("%s",A);
        int n = strlen(A);
        buildTree(1,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            TNode ans = query(1,a-1,b-1);
            printf("%d\n",2*ans.maxi);
        }
        return 0;
    }
