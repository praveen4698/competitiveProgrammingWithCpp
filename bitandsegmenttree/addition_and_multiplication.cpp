#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    struct TNode
    {
        int l,r ,reset,val;
        long long int mul,add;
        long long int sum;
        TNode() : l(0), r(0),mul(1LL),add(0LL),reset(0),val(0) {};// constructor

        void assignLeaf(int value)
        {
            sum = 1LL*value;
            mul = 1LL;
            add = 0LL;
        }

        void merge(TNode& left, TNode& right)
        {
           sum = (left.sum + right.sum)%mod;
        }

    };

    TNode nodes[800000];
    int A[1000001];
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

    int query(int st,int lo,int hi)
    {
        if( nodes[st].reset > 0)
        {
            nodes[st].add = 0 ;
            nodes[st].mul = 1;
            nodes[st].sum = ((nodes[st].r - nodes[st].l + 1)*nodes[st].val)%mod;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].reset = 1;
                nodes[2*st].val = nodes[st].val;
                nodes[2*st +1].reset = 1;
                nodes[2*st+1].val = nodes[st].val;
            }
            nodes[st].reset = 0;
            nodes[st].val = 0;
        }
        if( nodes[st].mul > 1)
        {
            nodes[st].sum = nodes[st].sum*nodes[st].mul%mod;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].mul = (nodes[2*st].mul*nodes[st].mul)%mod;
                nodes[2*st+1].mul = (nodes[2*st+1].mul*nodes[st].mul)%mod;
                nodes[2*st].add = (nodes[2*st].add*nodes[st].mul)%mod;
                nodes[2*st+1].add = (nodes[2*st+1].add*nodes[st].mul)%mod;
            }
            nodes[st].mul = 1;
        }
        if( nodes[st].add > 0)
        {
            nodes[st].sum = (nodes[st].sum + nodes[st].add)%mod;
            if( nodes[st].l != nodes[st].r)
            {

                nodes[2*st].add = (nodes[2*st].add+nodes[st].add)%mod;
                nodes[2*st+1].add = (nodes[2*st+1].add+nodes[st].add)%mod;
            }
            nodes[st].add = 0;
        }
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            int  res = nodes[st].sum;
            return res;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        int res;
        if( lo > mid)
        {
            res = query(2*st+1,lo,hi);

        }
        else if( hi <= mid)
            res = query(2*st,lo,hi);
        else
        {
            int  lr = query(2*st, lo, mid);
            int  rr = query(2*st+1, mid+1, hi);
            res = (lr+rr)%mod;
        }
		return res;

    }

     void update2(int st, int lo, int hi,int x,int value)
    {
        if( nodes[st].reset > 0)
        {
            nodes[st].add = 0 ;
            nodes[st].mul = 1;
            nodes[st].sum = ((nodes[st].r - nodes[st].l + 1)*nodes[st].val)%mod;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].reset = 1;
                nodes[2*st].val = nodes[st].val;
                nodes[2*st +1].reset = 1;
                nodes[2*st+1].val = nodes[st].val;
            }
            nodes[st].reset = 0;
            nodes[st].val = 0;
        }
        if( nodes[st].mul > 1)
        {
            nodes[st].sum = nodes[st].sum*nodes[st].mul%mod;
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].mul = (nodes[2*st].mul*nodes[st].mul)%mod;
                nodes[2*st+1].mul = (nodes[2*st+1].mul*nodes[st].mul)%mod;
                nodes[2*st].add = (nodes[2*st].add*nodes[st].mul)%mod;
                nodes[2*st+1].add = (nodes[2*st+1].add*nodes[st].mul)%mod;
            }
            nodes[st].mul = 1;
        }
        if( nodes[st].add > 0)
        {
            nodes[st].sum = (nodes[st].sum + nodes[st].add)%mod;

           if( nodes[st].l != nodes[st].r)
            {

                nodes[2*st].add = (nodes[2*st].add+nodes[st].add)%mod;
                nodes[2*st+1].add = (nodes[2*st+1].add+nodes[st].add)%mod;
            }
            nodes[st].add = 0;
        }
        if( nodes[st].l > hi || nodes[st].r < lo)
            return ;
        if (nodes[st].l == lo && nodes[st].r == hi)
        {
                if( x == 1)
                {
                    nodes[st].add = (nodes[st].r - nodes[st].l + 1)*value;
                }
                else if( x == 2)
                {
                    nodes[st].mul = (nodes[st].mul * value)%mod;
                    nodes[st].add = (nodes[st].add * value)%mod;
                }
                else
                {
                    nodes[st].reset = 1;
                    nodes[st].val = value;
                }
                if( nodes[st].reset > 0)
                {
                    nodes[st].add = 0 ;
                    nodes[st].mul = 1;
                    nodes[st].sum = ((nodes[st].r - nodes[st].l + 1)*nodes[st].val)%mod;
                    if( nodes[st].l != nodes[st].r)
                    {
                        nodes[2*st].reset = 1;
                        nodes[2*st].val = nodes[st].val;
                        nodes[2*st +1].reset = 1;
                        nodes[2*st+1].val = nodes[st].val;
                    }
                    nodes[st].reset = 0;
                    nodes[st].val = 0;
                }
                if( nodes[st].mul > 1)
                {
                    nodes[st].sum = nodes[st].sum*nodes[st].mul%mod;
                    if( nodes[st].l != nodes[st].r)
                    {
                        nodes[2*st].mul = (nodes[2*st].mul*nodes[st].mul)%mod;
                        nodes[2*st+1].mul = (nodes[2*st+1].mul*nodes[st].mul)%mod;
                        nodes[2*st].add = (nodes[2*st].add*nodes[st].mul)%mod;
                        nodes[2*st+1].add = (nodes[2*st+1].add*nodes[st].mul)%mod;
                    }
                    nodes[st].mul = 1;
                }
                if( nodes[st].add > 0)
                {
                    nodes[st].sum = (nodes[st].sum + nodes[st].add)%mod;

                    if( nodes[st].l != nodes[st].r)
                    {

                        nodes[2*st].add = (nodes[2*st].add+nodes[st].add)%mod;
                        nodes[2*st+1].add = (nodes[2*st+1].add+nodes[st].add)%mod;
                    }
                    nodes[st].add = 0;
                }
            return;
        }

        int mid = (nodes[st].l + nodes[st].r) / 2;
        if (lo > mid)
         {
             update2(2*st+1,lo,hi,x, value);
             update2(2*st,lo,hi,x, value);
         }
        else if (hi <= mid)
         {
             update2(2*st,lo,hi,x, value);
             update2(2*st+1,lo,hi,x, value);

         }
        else
        {
            update2(2*st ,lo, mid,x, value);
            update2(2*st+1,mid+1,hi,x, value);
        }
            nodes[st].merge(nodes[2*st], nodes[2*st+1]);
        }
       int main()
       {
           int n,q;
           scanf("%d %d",&n,&q);
           for(int i=0;i<n;++i)
           {
               scanf("%d",&A[i]);
           }
           buildTree(1,0,n-1);

           while(q--)
           {
               int a,b,c;
               scanf("%d %d %d",&a,&b,&c);
               if( a == 4)
                    printf("%d\n",query(1,b-1,c-1));
               else
                {
                    int d;
                    scanf("%d",&d);
                    update2(1,b-1,c-1,a,d);
               //     printf("%d\n",query(1,b-1,c-1));
                }

           }
          for(int i=1;i<15;++i)
          {
               printf("%d %d %d\n",nodes[i].l,nodes[i].r,nodes[i].sum);
        }
           return 0;
       }
