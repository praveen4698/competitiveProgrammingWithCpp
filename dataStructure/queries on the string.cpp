
#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int(i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    struct SegmentTreeNode
    {
        int total,countpre[3] ,countsuf[3] ;
        long long int count ;

        void assignLeaf(int value)
        {
               lp( i,0,3)
               {
                   countpre[i] = 0;
                   countsuf[i] = 0;
               }
               countpre[value] = 1;
               countsuf[value] = 1;
               total = value;
               count = 0;
               if( value == 0)
               {
                   count = 1;
               }
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
                count = left.count + right.count;
               // printf("leftcount = %d rightcount = %d\n",left.count,right.count);
                 lp(i,0,3)
                 {
                     lp(j,0,3)
                     {
                         if( (i+j)%3 == 0)
                         {
                           //  printf("%d %d\n",left.countsuf[i],right.countpre[j]);
                            count = count + (long long int )left.countsuf[i]*(long long int)right.countpre[j];
                         }
                     }
                   //  printf("count = %d\n",count );
                 }

                 lp(i,0,3)
                 {
                     countpre[i] = left.countpre[i] + right.countpre[(6 - left.total + i)%3];
                     countsuf[i] = right.countsuf[i] + left.countsuf[(6 - right.total + i)%3];
                 }
                 total = ( left.total + right.total)%3;
        }

        int getValue()
        {
            return 0;
        }
    };

    SegmentTreeNode nodes[800000];
    // left - right are used to denote the range of node of the segment tree
    // lo - hi are used on which length the query is performed
    void buildTree(string A,int stindex,int left,int right)
    {
        if(left == right)
        {
              // printf("%d\n",A[left] - '0');
               nodes[stindex].assignLeaf((A[left] - '0')%3 );
               return ;
        }
        int mid = (left + right)/2;
        buildTree(A,stindex*2,left,mid);
        buildTree(A,stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
       // printf("%d %d %d \n",nodes[stindex].count ,left,right);
    }

    SegmentTreeNode query(int stindex,int left,int right,int lo,int hi)
    {
        if(left == lo && right == hi)
            return nodes[stindex];
        int mid = (left + right)/2;
        if( lo > mid)
            return query(2*stindex+1,mid+1,right,lo,hi);
        if( hi <= mid)
            return query(2*stindex,left,mid,lo,hi);

        SegmentTreeNode leftResult = query(2*stindex, left, mid, lo, mid);
		SegmentTreeNode rightResult = query(2*stindex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		//printf("%d %d %d %d\n",leftResult.count,rightResult.count,lo,hi);
		result.merge(leftResult, rightResult);
		return result;

    }
	void update(int stindex, int left, int right, int index, int value)
	 {
		if (left == right)
        {
			nodes[stindex].assignLeaf(value);
			return;
		}

		int  mid = (left + right) / 2;
		if (index <= mid)
			update(stindex*2, left, mid, index, value);
		else
			update(stindex*2+1, mid+1, right, index, value);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}

	int main()
	{
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
	    int n,m;
	    string A;
	    scanf("%d %d",&n,&m);
	    cin>>A;
	    buildTree(A,1,0,n-1);
	    while(m--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if( a == 1)
            {
                update(1,0,n-1,b-1,c%3);
            }
            else
            {
                SegmentTreeNode re = query(1,0,n-1,b-1,c-1);
                printf("%lld\n",re.count);
            }

        }
        return 0;
	}
