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

        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {

        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {

        }
        void addupdate(int value)
        {

        }
        bool haspendingupdate()
        {

        }
        void applypendingupdate()
        {

        }
        int getpendingupdate()
        {

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
            if( result.haspendingupdate())  // for lazy;
                 result.applypendingupdate();
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
		if( nodes[stindex].haspendingupdate())   // for lazy
         {
            result.addupdate(nodes[stindex].getpendingupdate());
            result.applypendingupdate();
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

	// another one

        void update2(int stindex, int lo, int hi,int value)
        {
            if (nodes[stindex].left == nodes[stindex].right)
            {
                nodes[stindex].addupdate(value);
                return;
            }

            int mid = (nodes[stindex].left + nodes[stindex].right) / 2;
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




        void updatelazy(int stindex, int lo, int hi)
        {
            if( nodes[stindex].up > 0)
            {
               // printf("left = %d, right = %d",nodes[stindex].left,nodes[stindex].right);
                nodes[stindex].querypropagate(nodes[stindex].up);
                if( nodes[stindex].left != nodes[stindex].right)
                {
                    nodes[2*stindex].up = nodes[2*stindex].up + nodes[stindex].up;
                    nodes[2*stindex+1].up = nodes[2*stindex+1].up + nodes[stindex].up;
                }
                nodes[stindex].up = 0;
            }

            if( hi < nodes[stindex].left || lo > nodes[stindex].right)
                 return ;
            if( (nodes[stindex].left >= lo) && (hi >= nodes[stindex].right))
            {
              //  printf("left = %d, right = %d",nodes[stindex].left,nodes[stindex].right);
                nodes[stindex].propagate();
                if( nodes[stindex].left != nodes[stindex].right)
                {
                    nodes[stindex*2].up = nodes[2*stindex].up+1;
                    nodes[stindex*2+1].up = nodes[2*stindex+1].up+1;

                }
                return ;
            }

            update(2*stindex,lo,hi);
            update(2*stindex+1,lo,hi);
            nodes[stindex].merge(nodes[2*stindex],nodes[2*stindex+1]);
        }
    int querylazy(int stindex,int lo,int hi)
    {

        if( nodes[stindex].up > 0 )
        {
            nodes[stindex].querypropagate(nodes[stindex].up);
            if( nodes[stindex].left != nodes[stindex].right)
            {
                nodes[stindex*2].up = nodes[stindex*2].up + nodes[stindex].up;
                nodes[stindex*2+1].up = nodes[stindex*2+1].up + nodes[stindex].up;

            }
            nodes[stindex].up = 0;
        }
        if(nodes[stindex].left > hi || nodes[stindex].right < lo)
            return 0;

        if( nodes[stindex].left >= lo && nodes[stindex].right <= hi)
        {

            int ans = 0;
            lp(i,0,10)
                ans = ans + i*nodes[stindex].A[i];
            return ans;
        }
        int lr = query(2*stindex,lo,hi);
        int rr =  query(2*stindex+1,lo,hi);
        nodes[stindex].merge(nodes[2*stindex+1],nodes[2*stindex]);
        return (lr + rr);
    }
