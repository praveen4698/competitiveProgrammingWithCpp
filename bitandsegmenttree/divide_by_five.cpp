#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5;
    string A;
    int pre[lim];
    void preprocess()
    {
        pre[0] = 1;
        for(int i=1;i<lim;++i)
            pre[i] = (2*pre[i-1])%5;
        return ;
    }
        struct TNode
    {
        int l,r ;
        int len,ans;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            ans = value;
            len = 1;
        }

        void merge(TNode& left, TNode& right)
        {
            ans =  ((left.ans*pre[right.len])%5 + right.ans)%5;
            len = left.len + right.len;
        }

    };

    TNode nodes[800000];
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(A[lo]-'0');
               return ;
        }
        int mid = (lo + hi)>>1;
        buildTree(st<<1,lo,mid);
        buildTree(st<<1|1,mid+1,hi);
        nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
    }

    TNode query(int st,int lo,int hi)
    {

      //  cout<<"ss"<<endl;
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
       // cout<<"ss1"<<endl;
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
        cin>>t;
        preprocess();
        while(t--)
        {
            cin>>A;
            int n = A.length();
            buildTree(1,0,n-1);
            int q;
            cin>>q;
            while(q--)
            {
                int a,b,c;
                cin>>a>>b>>c;
                if( a == 1)
                    update(1,b,c);
                else
                    cout<<query(1,b,c).ans<<endl;

            }
        }
        return 0;
    }
