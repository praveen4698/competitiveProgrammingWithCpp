#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6;
    struct TNode
    {
        int l,r ;
        //multiset<int> S;
        unordered_map<int,int> M;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
           // S.insert(value);
            M[value] = 1;
        }

        void merge(TNode& left, TNode& right)
        {

            for(auto a:left.M)
                M[a.first]+=a.second;
            for(auto a:right.M)
                M[a.first]+=a.second;
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

    int check  ;
    int lower,lowervalue;
    void query(int st,int lo,int hi,int value)
    {
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
           // auto res = nodes[st].S.upper_bound(value);
            if( nodes[st].M[value] > 0)
                check = 1;
            return ;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        TNode res;
        if( lo > mid)
            query(2*st+1,lo,hi,value);
        else if( hi <= mid)
             query(2*st,lo,hi,value);
        else
        {
            query(2*st, lo, mid,value);
            query(2*st+1, mid+1, hi,value);

        }
		return ;
    }
    void update(int st ,int index, int oldvalue,int newvalue)
	 {

        nodes[st].M[oldvalue]--;
        nodes[st].M[newvalue]++;

		if (nodes[st].l == nodes[st].r)
        {

			return;
		}

		int  mid = (nodes[st].l + nodes[st].r)>>1;
		if (index <= mid)
			update(st<<1, index, oldvalue,newvalue);
		else
			update(st<<1|1, index, oldvalue,newvalue);

		//nodes[st].merge(nodes[st<<1], nodes[st<<1|1]);
	}
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,q;
            scanf("%d %d",&n,&q);
            for(int i=0;i<n;++i)
                scanf("%d",&A[i]);
            buildTree(1,0,n-1);
            while(q--)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                if(a == 2)
                {
                    update(1,b-1,A[b-1],c);
                    A[b-1] = c;

                }
                else
                {

                    int mid = A[b-1]+A[c-1];
                    mid = mid/2;
                    int i = mid;
                    while(1)
                    {
                        check = -1;
                        query(1,b-1,c-1,i);
                        if( check == 1)
                            break;
                        i++;

                    }
                    ll ans = (i-A[b-1])*1LL*(A[c-1]-i);
                    int j = mid;
                    int k = i-mid+1;
                    while(k--)
                    {
                        check = -1;
                        query(1,b-1,c-1,j);
                        if( check == 1)
                            break;
                        j--;

                    }
                    ans = max(ans, (j-A[b-1])*1LL*(A[c-1]-j));
                    printf("%lld\n",ans);
                }
            }
        }
        return 0;
    }
