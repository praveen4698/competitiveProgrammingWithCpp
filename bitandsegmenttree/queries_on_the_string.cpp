#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    struct TNode
    {
        int l,r ;
        long long int prefix[3],suffix[3],sum,ans;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf( int value)
        {
            sum = (long long int)(value%3);
            if( sum == 0)
                ans = long long int (1);
            for(int i=0;i<3;++i)
            {
                prefix[i] = 0LL;
                suffix[i] = 0LL;
            }
            prefix[sum] = 1LL;
            suffix[sum] = 1LL;


        }

        void merge(TNode& left, TNode& right)
        {
            for(int i=0;i<3;++i)
            {
                prefix[i] = (long long int)left.prefix[i];
                suffix[i] = (long long int)right.suffix[i];
            }
            for(int i=0;i<3;++i)
            {
                prefix[(left.sum+i)%3] += right.prefix[i];
                suffix[(right.sum+i)%3]+= left.suffix[i];
            }
            sum = ((long long int)left.sum+1LL*right.sum)%3;
            ans = 1LL*left.ans + 1LL*right.ans;
            ans += (left.suffix[0]*right.prefix[0]) ;
            ans += (left.suffix[1]*right.prefix[2]);
            ans += (left.suffix[2]*right.prefix[1]);
        }

    };

    TNode nodes[800000];
    long long int A[100001];
    void buildTree(int st,int lo,int hi)
    {
       // printf("yo\n");
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
    void update(int st ,int index,long long int value)
	 {

		if (nodes[st].l == index)
        {
			nodes[st].assignLeaf(value);
			return;
		}

		int  mid = (nodes[st].l + nodes[st].r) / 2;
		if (index <= mid)
			update(st*2, index, value);
		else
			update(st*2+1, index, value);

		nodes[st].merge(nodes[2*st], nodes[2*st+1]);
	}
    int main()
    {
        int n,q;
        scanf("%d %d",&n,&q);
        char X[1000001];
        scanf("%s",X);
        for(int i=0;i<n;++i)
            A[i] = (long long int)(X[i]-'0');
        buildTree(1,0,n-1);
        while(q--)
        {
            int a;

            scanf("%d",&a);
            if( a == 2)
            {
                int b,c;
                scanf("%d %d",&b,&c);
                printf("%lld\n",query(1,b-1,c-1).ans);
            }
            else
            {
                 int b;
                 long long int c;
                 scanf("%d %lld",&b,&c);
                 update(1,b-1,c);
            }
        }
        return 0;
    }
