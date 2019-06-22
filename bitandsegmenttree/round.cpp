#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6;
    ll mod = 1e9+7;
    ll A[lim],sum;
        struct TNode
    {
        int l,r ;
        ll sum;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(ll value)
        {
            sum = 1ll*value;
            if( sum < 0)
                sum+=mod;

        }

        void merge(TNode& left, TNode& right)
        {
            sum = 1ll*(left.sum+right.sum);
            sum%=mod;
            if(sum < 0)
                sum+=mod;
        }

    };

    TNode nodes[8000000];
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

    ll query(int st,int lo,int hi)
    {

        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            ll res = nodes[st].sum;
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        ll res;
        if( lo > mid)
            res = query(2*st+1,lo,hi);
        else if( hi <= mid)
            res = query(2*st,lo,hi);
        else
        {
            ll lr = query(2*st, lo, mid);
            ll rr = query(2*st+1, mid+1, hi);
            res = lr+rr;
        }
		return res%mod;

    }
   void update(int st ,int index, int value)
	 {
        nodes[st].sum+=(1ll*value);
		if (nodes[st].l == nodes[st].r)
        {

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
        cin>>q>>n;
        sum = 0ll;
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
            sum+=A[i];
            if(sum < 0)
                sum+=mod;
        }
        for(int i=n;i<2*n;++i)
            A[i] = A[i-n];
        buildTree(1,0,2*n - 1);
        while(q--)
        {
            int x,u,d;
            ll y;
            cin>>x>>u>>d>>y;
            int first = u%d;
            int last = u;
            int s = ((last-first)/d + 1)*(last+first)/(2);
           // cout<<s<<endl;
            s++;
            int round = (s)/n;
            ll ans = sum*1ll*round%mod;
            if( s%n > 0)
            {
                //cout<<x-1<<" "<<s%n+x-2<<endl;
                ans+=query(1,x-1,s%n+x-2);

            }
            if( ans < 0)
                ans+=(1ll*mod);
            cout<<ans%mod<<endl;
            if( y < 0)
                y+=mod;
            update(1,x-1,y);
            update(1,x-1+n,y);
            sum+=(1ll*y);
            A[x-1] += (1ll*y);
           // update(1,x-1,A[x-1],y);

        }
        return 0;
    }
