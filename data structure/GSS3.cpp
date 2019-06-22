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
	void update(int stindex ,int index, int value)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].assignLeaf(value);
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index, value);
		else
			update(stindex*2+1, index, value);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}

    int main()
    {
        int c,n,A[100001];
        scanf("%d",&n);
        lp(i,0,n)
            scanf("%d",&A[i]);
        buildTree(A,1,0,n-1);
        scanf("%d",&c);
        while(c--)
        {
            int i,a,b;

            scanf("%d %d %d",&i,&a,&b);
            if( i == 1)
            {
                SegmentTreeNode re = query(1,a-1,b-1);
                printf("%d\n",re.maxi);
            }
            else
                update(1,a-1,b);

        }
        return 0;
    }
