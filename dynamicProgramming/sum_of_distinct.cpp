#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim == 5e5+10;
    long long int A[lim];
    struct TNode
    {
        int l,r ;
        set<int> distinct;
        long long int sum;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            sum = 1LL*value;
            distinct.insert(value);
        }

        void merge(TNode& left, TNode& right)
        {

            for(auto it:left.distinct)
                distinct.insert(it);
            for(auto it::right.distinct)
                distinct.insert(it)
            sum = 0LL;
            for(auto it::distinct)
                sum+=distinct;

        }

    };
    TNode nodes[800000];
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
    long long int query(int st,int lo,int hi)
    {

        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            return nodes[st].sum;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        TNode res;
        if( lo > mid)
            return query(2*st+1,lo,hi);
        else if( hi <= mid)
            return  query(2*st,lo,hi);
        else
        {
            return  query(2*st, lo, mid) + query(2*st+1, mid+1, hi);
            TNode rr = query(2*st+1, mid+1, hi);
            res.l = lr.l;
            res.r = rr.r;
            res.merge(lr, rr);
        }
		return res;

    }
    int main()
    {

        return 0;
    }

