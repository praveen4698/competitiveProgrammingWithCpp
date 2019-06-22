#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
     struct TNode
    {
        int l,r ;
        int maxi,mini;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            maxi = mini = value;
        }

        void merge(TNode& left, TNode& right)
        {
            maxi = max(left.maxi,right.maxi);
            mini = min(left.mini,right.mini);
        }

    };
    TNode nodes[800000];
    int A[1000001];
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
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        int q;
        scanf("%d",&q);
        buildTree(1,0,n-1);
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            TNode res = query(1,a,b);
            int temp = res.mini;
            double ans;

                 ans = (double)(1.0*res.mini) + (double)(res.maxi - res.mini)/2.0;
            if( a > 0)
            {
                res = query(1,0,a-1);
                ans = max(ans,(double)1.0*temp + (double)res.maxi);
            }
            if( b <n-1)
            {
                res = query(1,b+1,n-1);
                ans = max(ans,(double)temp + (double)res.maxi);
            }
            printf("%.1f\n",ans);
        }
        return 0;
    }
