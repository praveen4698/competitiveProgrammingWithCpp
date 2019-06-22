#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    int A[lim],a[lim];
    vector<int> prime;

    void seive()
    {
        for(int i=0;i<lim;++i)
            A[i] = 0;
        for(int i=2;i*i<=lim;++i)
        {
            if( A[i] == 0)
            {
                for(int j=2*i;j<lim;j=j+i)
                    A[j] = 1;
            }
        }
        for(int i=2;i*i<=lim;++i)
            if( A[i] == 0)
                prime.push_back(i);
    }
    struct TNode
    {
        int l,r ;
        vector<int> p;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            for(auto i:prime )
            {
                while(value%i == 0)
                {
                    p.push_back(i);
                    value = value/i;
                }
            }
            if(value > 1)
                p.push_back(value);
           // sort(p.begin(),p.end());
        }

        void merge1(TNode& left, TNode& right)
        {
           // printf("in ");
            vector<int>::iterator one = left.p.begin();
            vector<int>::iterator two = right.p.begin();
            while(one != left.p.end() && two != right.p.end())
            {
                if( *one < *two)
                {
                    p.push_back(*one);
                    one++;
                }
                else
                {
                    p.push_back(*two);
                    two++;
                }
            }
            if( one == left.p.end())
            {
                while(two != right.p.end())
                {
                    p.push_back(*two);
                    two++;
                }
            }
            else
            {
                while(one != left.p.end())
                {
                    p.push_back(*one);
                    one++;
                }
            }
           // printf("out \n");
        }

    };
    TNode nodes[800000];
    void buildTree(int st,int lo,int hi)
    {
        //printf("%d %d\n",lo,hi);
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(a[lo]);
               return ;
        }
        int mid = (lo + hi)/2;
        buildTree(st*2,lo,mid);
        buildTree(st*2+1,mid+1,hi);
        nodes[st].merge1(nodes[st*2],nodes[st*2+1]);
    }
    int  query(int st,int lo,int hi,int x,int y)
    {
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            int temp1 = lower_bound(nodes[st].p.begin(),nodes[st].p.end(),x) - nodes[st].p.begin();
            int temp2 = upper_bound(nodes[st].p.begin(),nodes[st].p.end(),y) - nodes[st].p.begin();

            int res = temp2 - temp1;
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        int res;
        if( lo > mid)
            res = query(2*st+1,lo,hi,x,y);
        else if( hi <= mid)
            res = query(2*st,lo,hi,x,y);
        else
        {
            int lr = query(2*st, lo, mid,x,y);
            int rr = query(2*st+1, mid+1, hi,x,y);
            res = lr + rr;
        }
		return res;

    }
    int main()
    {
        seive();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        buildTree(1,0,n-1);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int l,r,x,y;
            scanf("%d %d %d %d",&l,&r,&x,&y);
            int res = query(1,l-1,r-1,x,y);
            printf("%d\n",res);
        }
        return 0;
    }
