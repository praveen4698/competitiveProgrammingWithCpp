#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

     const int lim = 1e5+10;
     struct TNode
    {
        int l,r ;
        int minvalue,up;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            minvalue = value;
            up = 0;
        }

        void merge(TNode& left, TNode& right)
        {
            minvalue = min(left.minvalue+left.up , right.minvalue+right.up);
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

    int  query(int st,int ri)
    {

        if(nodes[st].l == ri && nodes[st].r == ri)
        {
            int  res = nodes[st].l;
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        int res;
        if( ri > mid)
             res = query(2*st+1,ri);
        else if( ri <= mid)
            res = query(2*st,ri);
        nodes[st].merge(nodes[2*st],nodes[2*st+1]);
		return res;

    }
    int main()
    {
        return 0;
    }
