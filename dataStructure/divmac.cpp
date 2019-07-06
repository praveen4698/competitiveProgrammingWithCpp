#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define maxi 1000005
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int p[maxi];
    int seive()
    {
        p[0] = p[1] = 1;
        loop(i,0,maxi)
        {
            p[i] = 1;
        }
        for(int i = 2;i*i<=maxi;++i)
        {
            if( p[i] == 1)
            {
                p[i] = i;
                for(int j = 2*i;j <= maxi; j = j+i)
                {
                    if( p[j] == 1)
                        p[j] = i;
                }
            }
        }
    }
    struct SegmentTreeNode
    {
        int X ;

        void assignLeaf(int value)
        {
              X = value;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
                X = max(left.getValue(),right.getValue());
        }

        int getValue()
        {
            return X;
        }
    };

    SegmentTreeNode nodes[800000];
    int A[maxi];
    // left - right are used to denote the range of node of the segment tree
    // lo - hi are used on which length the query is performed
    void buildTree(int stindex,int left,int right)
    {
        if(left == right)
        {
               nodes[stindex].assignLeaf(p[A[left]]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }

    SegmentTreeNode query(int stindex,int left,int right,int lo,int hi)
    {
        if( nodes[stindex].getValue() == 1)
        {
            return nodes[stindex];
        }
        if(left == lo && right == hi)
            return nodes[stindex];
        int mid = (left + right)/2;
        if( lo > mid)
            return query(2*stindex+1,mid+1,right,lo,hi);
        if( hi <= mid)
            return query(2*stindex,left,mid,lo,hi);

        SegmentTreeNode leftResult = query(2*stindex, left, mid, lo, mid);
		SegmentTreeNode rightResult = query(2*stindex+1, mid+1, right,mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;



    }
	void update(int stindex, int left, int right, int lo ,int hi)
	 {
		if( lo > right || hi < left)
            return;
        if( nodes[stindex].X == 1)
            return ;
        if( left == right)
        {
            A[left] = A[left]/(nodes[stindex].X);
            nodes[stindex].assignLeaf(p[A[left]]);
            return ;

        }
        int mid = (left + right)/2;
        update(2*stindex, left, mid, lo, hi);
		update(2*stindex+1, mid+1, right, lo, hi);
		nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);

	}

	int main()
	{
	    int t;
	    scanf("%d",&t);
	    seive();
	    while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            loop(i,0,n)
            {
                scanf("%d",&A[i]);
            }
            buildTree(1,0,n-1);
            loop(i,0,m)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                if( a == 0)
                {
                     update(1,0,n-1,b-1,c-1);
                }
                else
                {
                    SegmentTreeNode result = query(1,0,n-1,b-1,c-1);
                    printf("%d ",result.getValue());
                }
            }
            printf("\n");
        }

        return 0;
	}

