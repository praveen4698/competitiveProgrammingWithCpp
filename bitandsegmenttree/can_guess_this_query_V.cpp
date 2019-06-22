#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    struct SegmentTreeNode
    {
        int left,right ;
        int maxi,sum,presum ,sufsum;
        SegmentTreeNode() : maxi(0),sum(0),presum(0),sufsum(0) {};// constructor

        void assignLeaf(int value)
        {
            maxi = sum = presum = sufsum = value;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            sum = left.sum + right.sum;
            presum = max(left.presum,left.sum + right.presum);
            sufsum = max(right.sufsum,right.sum + left.sufsum);
            maxi = max(presum,max(sufsum,max(left.maxi,max(right.maxi,left.sufsum+right.presum))));
        }


        int getValue()
        {
            return 0;
        }
    };

    SegmentTreeNode nodes[800000];
    // left - right are used to denote the range of node of the segment tree
    // lo - hi are used on which length the query is performed
    void buildTree(int A[],int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        if(left == right)
        {
               nodes[stindex].assignLeaf(A[left]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(A,stindex*2,left,mid);
        buildTree(A,stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }

    SegmentTreeNode query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            SegmentTreeNode result = nodes[stindex];
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

		return result;

    }

    int main()
    {
        int c,n,A[100001];
        int t;
        scanf("%d",&t);
        while(t--)
        {


        scanf("%d",&n);
        lp(i,0,n)
            scanf("%d",&A[i]);
        buildTree(A,1,0,n-1);
        scanf("%d",&c);
        while(c--)
        {
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a--;
            c--;
            b--;
            d--;
            int ans = -INF;
            if( c <= b)
            {
                ans = max(ans,query(1,a,b).sufsum + query(1,b,d).presum -A[b]);
                ans = max(ans,query(1,a,c).sufsum + query(1,c,d).presum - A[c]);
                ans = max(ans,query(1,c,b).maxi);
            }
            else
            {
                int temp = 0;
                if( b+1 > c-1)
                    temp = 0;
                else
                    temp = query(1,b+1,c-1).sum;
                ans = max(ans,query(1,a,b).sufsum + temp + query(1,c,d).presum );

            }
            printf("%d\n",ans);

        }
        }
        return 0;
    }
