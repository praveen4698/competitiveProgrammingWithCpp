#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    struct TNode
    {
        int l,r ;
        unordered_map<int,int> M;
        int trns,xor1;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            trns = 0;
            xor1 = 0;
            M[value] = 1;
        }

        void merge(TNode& left, TNode& right)
        {
            M.clear();
            for(auto m:left.M)
            {
                M[m.first^left.trns]+=m.second;
            }
            for(auto m:right.M)
            {
                M[m.first^right.trns]+=m.second;
            }
            //trns = 0;
            //xor1 = 0;
        }

    };

    TNode nodes[800000];
    int A[100001],S[100001];
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
    int ans ;
    void query(int st,int lo,int hi,int value)
    {
        if( nodes[st].trns != 0)
        {
            nodes[st].xor1^=nodes[st].trns;
            cout<<"ss"<<nodes[st].xor1<<"\n";
            if( nodes[st].l != nodes[st].r)
            {
                nodes[2*st].trns^=nodes[st].trns;
                nodes[2*st+1].trns^=nodes[st].trns;
            }
            nodes[st].trns = 0;
        }
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            int temp = (nodes[st].M[value^nodes[st].xor1])
            ans+=temp;
            return ;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;

        if( lo > mid)
           query(2*st+1,lo,hi,value);
        else if( hi <= mid)
            query(2*st,lo,hi,value);
        else
        {
            query(2*st, lo, mid,value);
            query(2*st+1, mid+1, hi,value);

        }


    }
    void update2(int st, int lo, int hi,int value)
        {
            if( nodes[st].trns != 0)
            {
                nodes[st].xor1^=nodes[st].trns;
                if( nodes[st].l != nodes[st].r)
                {
                    nodes[2*st].trns^=nodes[st].trns;
                    nodes[2*st+1].trns^=nodes[st].trns;
                }
                nodes[st].trns = 0;
            }
            nodes[st]
            if (nodes[st].l == nodes[st].r)
            {
                nodes[st].trns^=value;
                return  ;
            }
            if( nodes[st].l == lo && nodes[st].r == hi)
            {
                nodes[st].trns^=value;
                return ;
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
           // nodes[st].merge(nodes[2*st], nodes[2*st+1]);
    }
    int main()
    {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;++i)
        {
            cin>>S[i];
        }
        A[0] = S[0];
        for(int i=1;i<n;++i)
            A[i] = A[i-1]^S[i];
        buildTree(1,0,n-1);
        while(q--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if( a == 1)
            {
                update2(1,b-1,n-1,c^S[b-1]);
                S[b-1] = c;
                for(int i=0;i<16;i++)
                {
                    printf("l = %d r = %d trans -  %d zor %d\n",nodes[i].l,nodes[i].r,nodes[i].trns,nodes[i].xor1);
                }
             }
             else
             {
                 ans = 0;
                 query(1,0,b-1,c);
                 for(int i=0;i<16;i++)
                {
                    printf("l = %d r = %d trans -  %d zor %d\n",nodes[i].l,nodes[i].r,nodes[i].trns,nodes[i].xor1);
                }
                 cout<<ans<<endl;
             }
        }
        return 0;
    }
