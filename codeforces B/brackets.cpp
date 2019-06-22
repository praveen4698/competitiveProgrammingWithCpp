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
        int open,closed;
        SegmentTreeNode() : open(0),closed(0) {};// constructor

        void assignLeaf(char value)
        {
           if(value == '(')
                open = 1,closed = 0;
           else
                closed = 1,open = 0;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            int temp = min( left.open ,right.closed);
            open = left.open + right.open - temp;
            closed = right.closed + left.closed - temp;

        }
        void addupdate()
        {
            open = 1 - open;
            closed = 1 - closed;
        }

    };

    SegmentTreeNode nodes[800000];
    // left - right are used to denote the range of node of the segment tree
    // lo - hi are used on which length the query is performed
    void buildTree(char A[],int stindex,int left,int right)
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


	void update(int stindex ,int index)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].addupdate();

			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index);
		else
			update(stindex*2+1, index);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}

	// another one
    int main()
    {
        lp(j,1,11)
        {

            int n;
            char A[30001];
            scanf("%d",&n);
            scanf("%s",A);
            buildTree(A,1,0,n-1);
            int q;
            scanf("%d",&q);
            printf("Test %d:\n",j);
            lp(i,1,q+1)
            {

                int k;
                scanf("%d",&k);
                if( k == 0)
                {
                    if( nodes[1].open == 0 && nodes[1].closed == 0)
                        printf("YES\n");
                    else
                        printf("NO\n");

                }
                else
                    update(1,k-1);

            }
            lp(i,0,134000)
            {
                nodes[i].closed = 0;
                nodes[i].open = 0;
            }
        }
        return 0;
    }
