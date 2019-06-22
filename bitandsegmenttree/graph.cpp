#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

        struct TNode
    {
        int l,r ;
        int ones,zero,up;
        TNode() : l(0), r(0),ones(0),zero(0),up(0) {};// constructor

        void assignLeaf(int value)
        {
            if( value == 1)
                ones++;
            else
                zero++;

        }

        void merge(TNode& left, TNode& right)
        {
            ones = left.ones + right.ones;
            zero = left.zero + right.zero;
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
        int mid = (lo + hi)>>1;
        buildTree(st<<1,lo,mid);
        buildTree(st<<1|1,mid+1,hi);
        nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
    }

    TNode querylazy(int st,int lo,int hi)
    {
        nodes[st].up%=2;
        if( nodes[st].up != 0 )
        {
            swap(nodes[st].ones,nodes[st].zero);
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].up+=nodes[st].up;
                nodes[2*st+1].up+=nodes[st].up;
            }
            nodes[st].up = 0;
        }

        if(nodes[st].l > hi || nodes[st].r < lo)
        {
            TNode ss;
            ss.l = 0;
            ss.r = 0;
            ss.up = 0;
            ss.ones = 0;
            ss.zero = 0;
            return ss;
        }

        if( nodes[st].l >= lo && nodes[st].r <= hi)
        {
            return nodes[st];

        }
        TNode lr = querylazy(2*st,lo,hi);
        TNode  rr =  querylazy(2*st+1,lo,hi);
        TNode res ;
        res.l = lr.l;
        res.r = rr.r;
        res.merge(lr,rr);
        return res;
    }
        void updatelazy(int st, int lo, int hi)
        {
            //printf("%d %d %d %d\n",lo,hi,nodes[st].l,nodes[st].r);
            nodes[st].up%=2;
            if( nodes[st].up != 0 )
            {
                swap(nodes[st].ones,nodes[st].zero);
                if( nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up+=nodes[st].up;
                    nodes[2*st+1].up+=nodes[st].up;
                }
                nodes[st].up = 0;
            }

            if( hi < nodes[st].l || lo > nodes[st].r)
                 return ;
            if( (nodes[st].l >= lo) && (hi >= nodes[st].r))
            {
              //  printf("left = %d, r = %d",nodes[st].left,nodes[st].r);
                swap(nodes[st].ones,nodes[st].zero);
                if( nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].up+=1;
                    nodes[2*st+1].up+=1;
                }
                nodes[st].up = 0;
                return ;
            }

            updatelazy(2*st,lo,hi);
            updatelazy(2*st+1,lo,hi);
            nodes[st].merge(nodes[2*st],nodes[2*st+1]);
        }
    int main()
    {
        string S;
        int n,q;
        cin>>n>>q;
        cin>>S;
        for(int i=0;i<n-1;++i)
        {
            if( S[i] == '<')
                A[i] = 0;
            else
                A[i] = 1;
        }
        buildTree(1,0,n-2);
        while(q--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if( a == 1)
                updatelazy(1,b-1,c-2);
            else
            {
                if( c > b)
                {
                    cout<<querylazy(1,b-1,c-2).zero<<endl;
                }
                else
                {
                    cout<<querylazy(1,c-1,b-2).ones<<endl;
                }
            }
        }
        return 0;
    }
