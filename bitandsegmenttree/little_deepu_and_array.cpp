#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

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
        if( nodes[st].up < 0)
            {
               // printf("left = %d, r = %d",nodes[st].left,nodes[st].r);
                nodes[st].minvalue+=nodes[st].up;
                if( nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up = nodes[2*st].up + nodes[st].up;
                    nodes[2*st+1].up = nodes[2*st+1].up + nodes[st].up;
                }
                nodes[st].up = 0;
            }
        if(nodes[st].l == ri && nodes[st].r == ri)
        {
            int  res = nodes[st].minvalue;
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
    void updatelazy(int st,int value)
    {
            if( nodes[st].up < 0)
            {
               // printf("left = %d, r = %d",nodes[st].left,nodes[st].r);
                nodes[st].minvalue+=nodes[st].up;
                if( nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up = nodes[2*st].up + nodes[st].up;
                    nodes[2*st+1].up = nodes[2*st+1].up + nodes[st].up;
                }
                nodes[st].up = 0;
            }

            if( nodes[st].minvalue > value)
            {
                nodes[st].up-=1;
                return ;
            }
            if(nodes[st].l == nodes[st].r)
                return ;

            updatelazy(2*st,value);
            updatelazy(2*st+1,value);
            nodes[st].merge(nodes[2*st],nodes[2*st+1]);
    }

    int main()
    {
        vector<pair<int,int> > Arr;

        int n,q;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int a;
            cin>>a;
            Arr.push_back({a,i});
        }
        sort(Arr.begin(),Arr.end());
        for(int i=0;i<n;++i)
            A[i] = Arr[i].first;
        buildTree(1,0,n-1);
        cin>>q;
        while(q--)
        {
            int a;
            cin>>a;
            updatelazy(1,a);
        }
        for(int i=0;i<n;++i)
        {
            Arr[i].first = query(1,i);
            swap(Arr[i].first,Arr[i].second);
        }
        sort(Arr.begin(),Arr.end());
        for(auto a:Arr)
            cout<<a.second<<" ";
        return 0;
    }
