#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int rot(int a,int x)
    {
        vector<int> t;
        int aa = a;
        while(aa>0)
        {
            t.push_back(aa%10);
            aa/=10;
        }
        reverse(t.begin(),t.end());
        int ans = 0;
        for(int i=x;i<x+t.size();++i)
        {
            ans = 10*ans + t[i%t.size()];
        }
        return ans;
    }
    struct TNode
    {
        int l,r ;
        int arr[12];
        int ro;
        int p,add;
        TNode() : l(0), r(0),p(0),add(0) {};// constructor

        void assignLeaf(int value)
        {
            for(int i=0;i<12;++i)
            {
                arr[i] = rot(value,i);
            }

        }

        void merge(TNode& left, TNode& right)
        {
            for(int i=0;i<12;++i)
            {
                arr[i] = max(left.arr[(i+left.p)%12],right.arr[(i+right.p)%12]);
            }
        }

    };
    TNode nodes[8000000];
    int A[1000000];
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
    int  query(int st,int lo,int hi)
    {
        nodes[st].p%=12;
        if( nodes[st].add != 0)
        {
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].p+=nodes[st].add;
                nodes[2*st].add+=nodes[st].add;
                nodes[2*st+1].p+=nodes[st].add;
                nodes[2*st+1].add+=nodes[st].add;
                nodes[2*st+1].p%=12;
                nodes[2*st+1].p%=12;
            }
            nodes[st].add = 0;
        }
       // printf("sfs\n");
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            int res = nodes[st].arr[nodes[st].p];
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        int res;
        if( lo > mid)
            res = query(2*st+1,lo,hi);
        else if( hi <= mid)
            res = query(2*st,lo,hi);
        else
        {
            int lr = query(2*st, lo, mid);
            int rr = query(2*st+1, mid+1, hi);
            res = max(lr,rr);
        }

		return res;

    }
    void update2(int st, int lo, int hi,int value)
    {
        if( nodes[st].add != 0)
        {
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].p+=nodes[st].add;
                nodes[2*st].add+=nodes[st].add;
                nodes[2*st+1].p+=nodes[st].add;
                nodes[2*st+1].add+=nodes[st].add;
                nodes[2*st+1].p%=12;
                nodes[2*st+1].p%=12;
            }
            nodes[st].add = 0;
        }
        if (nodes[st].l == nodes[st].r)
        {
            nodes[st].p+=value;
            nodes[st].p%=12;
            nodes[st].add+=value;\
            return;
        }

        int mid = (nodes[st].l + nodes[st].r) / 2;
        if (lo > mid)
            update2(2*st+1,lo,hi, value);
        else if (hi <= mid)
            update2(2*st,lo,hi, value);
        else
        {
            update2(2*st ,lo, mid, value);
            update2(2*st+1,mid+1,hi, value);
        }
        nodes[st].merge(nodes[2*st], nodes[2*st+1]);
    }
    int main()
    {
        int n,m;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        buildTree(1,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--)
        {

            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(a == 0)
            {
                int d;
                scanf("%d",&d);
                update2(1,b,c,d);
            }
            else
            {
                printf("%d\n",query(1,b,c));
            }
        }
        return 0;
    }
