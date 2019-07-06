#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    long long int w;
    struct TNode
    {
        int l,r ;
        long long int ans;
        long long int prefixvalue,prefixlen,suffixlen,suffixvalue;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(long long int value)
        {
            prefixlen = 1;
            prefixvalue = value;
            suffixlen = 1;
            suffixvalue = value;
            ans = 0;
            if( w == 1)
                ans = 1;
        }

        void merge(TNode& left, TNode& right)
        {
            ans = left.ans + right.ans;
            if( left.suffixvalue == right.prefixvalue)
            {
                if( left.suffixlen >= w)
                    ans-=(left.suffixlen-w+1);
                if( right.prefixlen >= w)
                    ans-=(right.prefixlen-w+1);
                int t = left.suffixlen + right.prefixlen ;
                if( t >= w)
                    ans+=(t-w+1);
                if( left.prefixvalue == left.suffixvalue && left.prefixlen == left.r - left.l + 1)
                {
                    prefixlen = left.prefixlen + right.prefixlen;
                    prefixvalue = left.prefixvalue;
                }
                else
                {
                    prefixlen = left.prefixlen;
                    prefixvalue = left.prefixvalue;
                }
                if( right.suffixvalue == right.prefixvalue && right.suffixlen == right.r-right.l+1)
                {
                    suffixlen = right.suffixlen + left.suffixlen;
                    suffixvalue = right.suffixvalue;
                }
                else
                {
                    suffixlen = right.suffixlen;
                    suffixvalue = right.suffixvalue;
                }

            }
            else
            {
                prefixlen = left.prefixlen;
                prefixvalue = left.prefixvalue;
                suffixlen = right.suffixlen;
                suffixvalue = right.suffixvalue;
            }
        }

    };

    TNode nodes[800000];
    long long int A[100001];
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
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d %lld",&n,&w);
            for(int i=0;i<n;++i)
                scanf("%lld",&A[i]);
            buildTree(1,0,n-1);
            int q;
            scanf("%d",&q);
            while(q--)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                update(1,a-1,b);
                printf("%lld\n",nodes[1].ans);
            }
        }
        return 0;
    }
