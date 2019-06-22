#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    int A[lim],B[lim],C[lim];
    struct TNode
    {
        int l,r ;
        long long int andd,aur;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            andd = value;
            aur = 0;
        }

        void merge(TNode& left, TNode& right)
        {
            andd = (left.andd|left.aur)&(right.andd|right.aur);

            aur = 0;
        }

    };

    TNode nodes[800000];
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(0);
               return ;
        }
        int mid = (lo + hi)/2;
        buildTree(st*2,lo,mid);
        buildTree(st*2+1,mid+1,hi);
        nodes[st].merge(nodes[st*2],nodes[st*2+1]);
    }
    TNode query(int st,int lo,int hi)
    {
        if( nodes[st].aur != 0)
        {
            nodes[st].andd|=nodes[st].aur;
            if(nodes[st].l != nodes[st].r)
            {
                nodes[2*st].aur|=nodes[st].aur;
                nodes[2*st+1].aur|=nodes[st].aur;
            }
            nodes[st].aur= 0;

        }
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
           // printf("---%d %d %d\n",lo,hi,nodes[st].andd);
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
    void update2(int st, int lo, int hi,int value)
    {
        if( nodes[st].aur != 0)
        {
            nodes[st].andd|=nodes[st].aur;
            if(nodes[st].l != nodes[st].r)
            {
                nodes[2*st].aur|=nodes[st].aur;
                nodes[2*st+1].aur|=nodes[st].aur;
            }
            nodes[st].aur= 0;

        }
        if(nodes[st].l == lo && nodes[st].r == hi)
        {

            nodes[st].andd|=value;
           // printf("%d %d and = %d\n",lo,hi,nodes[st].andd);
            if(nodes[st].l != nodes[st].r)
            {
                nodes[2*st].aur|=value;
                nodes[2*st+1].aur|=value;
            }
            nodes[st].aur= 0;

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
        nodes[st].merge(nodes[2*st], nodes[2*st+1]);
        //printf("%d %d and = %d\n",nodes[st].l,nodes[st].r,nodes[st].andd);
    }
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        buildTree(1,0,n-1);
        for(int i=0;i<m;++i)
        {
            scanf("%d %d %d",&A[i],&B[i],&C[i]);
            update2(1,A[i]-1,B[i]-1,C[i]);
        }
        int flag = 0;
        TNode ans ;
        for(int i=0;i<m;++i)
        {
            ans = query(1,A[i]-1,B[i]-1);
           // printf("anndd = %d\n",ans.andd);
            if(ans.andd != C[i])
            {
                flag = 1;
                break;
            }
        }
        if( flag == 1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0;i<n;++i)
            {
                ans = query(1,i,i);
                printf("%d ",ans.andd);
            }
        }
        return 0;
    }
