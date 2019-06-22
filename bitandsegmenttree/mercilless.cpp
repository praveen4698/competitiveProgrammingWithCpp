#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5 + 10;
vector<int> G[lim];
int ind = 1,n;
int pos[lim],num[lim],w[lim];
int A[lim];
    void DFS(int u)
    {

        num[u] = 1;
        pos[u] = ind;
        ind++;
        for(int i = 0;i<G[u].size();++i)
        {
            int v = G[u][i];
            if(num[v] == 0)
            {
                DFS(v);
                num[u]+=num[v];
            }
        }
    }
    struct SegmentTreeNode
    {
        int left,right ;
        int mini;
        int poison,alive;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            mini = value;
            alive = 1;
            poison = 0;
            if( mini == INF)
                alive =0;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            mini = min(left.mini,right.mini);
            alive = left.alive + right.alive;
            poison = 0;
        }


    };
    SegmentTreeNode nodes[800000];
    // left - right are used to denote the range of node of the segment tree
    // lo - hi are used on which length the query is performed
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        if(left == right)
        {
               nodes[stindex].assignLeaf(A[left]);
             //  printf("pos[left] = %d\n",w[pos[left]]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }
    SegmentTreeNode query(int stindex,int lo,int hi)
    {

        if( nodes[stindex].alive == 0)
            return nodes[stindex];
        if( nodes[stindex].poison > 0)
        {
            nodes[stindex].mini-=nodes[stindex].poison;
            if( nodes[stindex].left != nodes[stindex].right)
            {
                nodes[2*stindex].poison+=nodes[stindex].poison;
                nodes[2*stindex+1].poison+=nodes[stindex].poison;
            }
            nodes[stindex].poison = 0;

        }
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            SegmentTreeNode result = nodes[stindex];
          //  printf("left = %d right = %d alive = %d\n",nodes[stindex].left,nodes[stindex].right,nodes[stindex].alive);
            return result;
        }
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;
        SegmentTreeNode result;
        if( lo > mid)
            result = query(2*stindex+1,lo,hi);
        else if( hi <= mid)
            result = query(2*stindex,lo,hi);
        else
        {
            SegmentTreeNode leftResult = query(2*stindex, lo, mid);
            SegmentTreeNode rightResult = query(2*stindex+1, mid+1, hi);
            result.left = leftResult.left;
            result.right = rightResult.right;
            result.merge(leftResult, rightResult);
        }
      //  printf("left = %d right = %d alive = %d\n",result.left,result.right,result.alive);
		return result;
    }
    void update2(int stindex, int lo, int hi,int value)
    {
        if( nodes[stindex].alive == 0)
            return ;
        if( nodes[stindex].poison > 0)
        {
            nodes[stindex].mini-=nodes[stindex].poison;
            if( nodes[stindex].left != nodes[stindex].right)
            {
                    nodes[2*stindex].poison+=nodes[stindex].poison;
                    nodes[2*stindex+1].poison+=nodes[stindex].poison;
            }
            nodes[stindex].poison = 0;

        }
        if (nodes[stindex].left == nodes[stindex].right)
        {

            nodes[stindex].mini-=value;
            if(nodes[stindex].mini <= 0)
            {
                nodes[stindex].alive = 0;
                nodes[stindex].mini = INF;

            }
            return;
        }
        int mid = (nodes[stindex].left + nodes[stindex].right) / 2;
        if( nodes[stindex].left == lo && nodes[stindex].right == hi)
        {

            if( nodes[stindex].mini - value <= 0)
            {
                update2(2*stindex ,lo, mid, value);
                update2(2*stindex+1,mid+1,hi, value);
                nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
            }
            else
            {
               nodes[stindex].poison = value;
            }
            return ;
        }

        if (lo > mid)
            update2(2*stindex+1,lo,hi, value);
        else if (hi <= mid)
            update2(2*stindex,lo,hi, value);
        else
        {
            update2(2*stindex ,lo, mid, value);
            update2(2*stindex+1,mid+1,hi, value);
        }
        nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
    }
    int main()
    {
        scanf("%d",&n);
        w[0] = 10;
        for(int i=1;i<n+1;++i)
        {
            int a;
            scanf("%d %d",&w[i],&a);
                G[a].push_back(i);
                G[i].push_back(a);
        }
        DFS(0);
        for(int i=0;i<n+1;++i)
        {
            A[pos[i]] = w[i];
           // printf("pos[%d] %d   a = %d\n",i,pos[i],A[i]);
        }
        buildTree(1,1,n+1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<15;++i)
        {
          //  printf("left = %d right = %d alive = %d mini = %d\n",nodes[i].left,nodes[i].right,nodes[i].alive,nodes[i].mini);
        }
        while(q--)
        {
            int a;
            scanf("%d",&a);
            if( a == 1)
            {
                int b,c;
                scanf("%d %d",&b,&c);
                update2(1,pos[b]+1,pos[b]+num[b]-1,c);
            }
            else
            {
                int b;
                scanf("%d",&b);
                SegmentTreeNode res = query(1,pos[b]+1,pos[b]+num[b]-1);
                printf("%d\n",res.alive);

            }
        }
        return 0;
    }
