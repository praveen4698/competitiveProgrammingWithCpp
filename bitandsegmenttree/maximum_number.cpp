#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5 + 10;
    vector<int> prime[lim];
    bool p[lim];
    int arr[lim];
    void seive()
    {
        for(int i=0;i<lim;++i)
            p[i] = true;
        p[0] = p[1] = false;
        for(int i=2;i<lim;++i)
        {
            if(p[i] == true)
            {
                for(int j=i;j<lim;j=j+i)
                {
                    p[j] = false;
                    prime[j].push_back(i);
                }
            }
        }

    }
    struct TNode
    {
        int l,r ;
        int value ,cont;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int a)
        {
              value = a;
              cont = 1;

        }

        void merge(TNode& left, TNode& right)
        {
            if(left.value > right.value )
            {
                value = left.value;
                cont = left.cont;
            }
            else if( left.value < right.value)
            {
                value = right.value;
                cont = right.cont;
            }
            else
            {
                value = left.value;
                cont = left.cont + right.cont;
            }
        }

    };
    TNode nodes[2500000];
    vector<int> A;
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(arr[A[lo]]);
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

    vector<int> V[lim];
    int start[lim],endi[lim];
    int main()
    {
        seive();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&arr[i]);
            for(auto p:prime[arr[i]])
            {
                V[p].push_back(i);
            }

        }
        for(int i=2;i<lim;++i)
        {
            start[i] = A.size();
            for(auto v:V[i])
            {
                A.push_back(v);
            }
            endi[i] = A.size()-1;
        }
        buildTree(1,0,A.size()-1);
        while(m--)
        {
            int g,x,y;
            scanf("%d %d %d",&g,&x,&y);
            x--,y--;
            int maxi = -1;
            int cont = -1;
            for(auto a:prime[g])
            {
                if(start[a] > endi[a])
                    continue;
                int l = lower_bound(V[a].begin(),V[a].end(),x) - V[a].begin();
                int r = upper_bound(V[a].begin(),V[a].end(),y) - V[a].begin();
                l+=start[a];
                r+=start[a];
                if(l > r-1)
                    continue;
                TNode ans = query(1,l,r-1);
                if(ans.value > maxi)
                {
                    maxi = ans.value;
                    cont = ans.cont;
                }
            }
            printf("%d %d\n",maxi,cont);
        }
        return 0;
    }

