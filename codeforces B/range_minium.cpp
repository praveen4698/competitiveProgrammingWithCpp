#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

        struct TNode
    {
        int l,r ;
        int ans ;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            ans = value;
        }

        void merge(TNode& left, TNode& right)
        {
            ans = min(left.ans,right.ans);
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
        int mid = (lo + hi)>>1;
        buildTree(st<<1,lo,mid);
        buildTree(st<<1|1,mid+1,hi);
        nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
    }
   // int ans ;
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
    void update(int st ,int index, int value)
	 {

		if (nodes[st].l == nodes[st].r)
        {
			nodes[st].assignLeaf(value);
			return;
		}

		int  mid = (nodes[st].l + nodes[st].r)>>1;
		if (index <= mid)
			update(st<<1, index, value);
		else
			update(st<<1|1, index, value);

		nodes[st].merge(nodes[st<<1], nodes[st<<1|1]);
	}
    int main()
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        buildTree(1,0,n-1);
        while(q--)
        {
            char a;
            int b,c;
            cin>>a>>b>>c;
            if( a == 'q')
            {
                TNode ans = query(1,b-1,c-1);
                cout<<ans.ans<<endl;
            }
            else
                update(1,b-1,c);
        }
        return 0;
    }
