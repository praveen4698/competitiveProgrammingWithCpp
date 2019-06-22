#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    struct SegmentTreeNode
    {
        int left,right ;
        long long int sum,value;
        int invert;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(long long int data,long long int power)
        {
            value = data;
            sum = power;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            value = (left.value+right.value)%mod;
            sum = (left.sum+right.sum)%mod;
        }

    };

    SegmentTreeNode nodes[8000000];
    long long int two[lim];
    char S[lim],n;
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        if( left == right && right == n-1)
        {
            nodes[stindex].value = 0;
            nodes[stindex].sum = 0;
        }
        if(left == right)
        {
               nodes[stindex].assignLeaf(two[n-left-2]*(S[left]-'0'),two[n-left-2]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }
    void update2(int stindex, int lo, int hi)
    {
        if( nodes[stindex].invert == 1)
        {
            nodes[stindex].value = nodes[stindex].sum - nodes[stindex].value;
            if( nodes[stindex].value < 0)
                nodes[stindex].value+=mod;
            nodes[stindex].invert = 0;
            if( nodes[stindex].left != nodes[stindex].right)
            {
                nodes[2*stindex].invert^=1;
                nodes[2*stindex+1].invert^=1;
            }
        }
        if( nodes[stindex].left == nodes[stindex].right)
        {
            nodes[stindex].value = nodes[stindex].sum - nodes[stindex].value;
            if( nodes[stindex].value < 0)
                nodes[stindex].value+=mod;
            return;
        }
        if( nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            nodes[stindex].value = nodes[stindex].sum - nodes[stindex].value;
            if( nodes[stindex].value < 0)
                nodes[stindex].value+=mod;
            nodes[stindex].invert = 0;
            if( nodes[stindex].left != nodes[stindex].right)
            {
                nodes[2*stindex].invert^=1;
                nodes[2*stindex+1].invert^=1;
            }
            return;
        }

        int mid = (nodes[stindex].left + nodes[stindex].right) / 2;
        if (lo > mid)
            update2(2*stindex+1,lo,hi);
        else if (hi <= mid)
            update2(2*stindex,lo,hi);
        else
        {
            update2(2*stindex ,lo, mid);
            update2(2*stindex+1,mid+1,hi);
        }
        nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
    }
    long long int last ,k;
    long long int getAns()
    {
        long long int  res = nodes[1].value;
        if (last == 1) {
            ++res;
        } else if (!(k & 1)) {
            ++res;
        }
        if (res == mod) return 0;
            return res;
    }
    int main()
    {
        scanf("%s",S);
        n = strlen(S);
        two[0] = 1;
        for(int i=1;i<=n;++i)
            two[i] = (1LL*two[i-1]*2)%mod;

        for(auto a:S)
            if( a == '1')
                k++;
        buildTree(1,0,n-1);
        int last = S[n-1]-'0';
        int q;
        scanf("%d",&q);
        printf("%lld\n",getAns());
        last = S[n-1]-'0';
        while(q--)
        {
                int l,r;
                scanf("%d %d",&l,&r);
                k ^= (r - l + 1) & 1;
                if (r == n) {
                    --r;
                    last ^= 1;
                }
                update2(1,l-1,r-1);
                printf("%lld\n",getAns());

        }
        return 0;
    }
