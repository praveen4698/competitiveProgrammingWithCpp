#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
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
        long long int sum , up;
        SegmentTreeNode() : sum(0),up(0) {};// constructor

        void assignLeaf()
        {
           sum = (long long int)0;
           up = (long long int )0;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
              sum = left.sum + right.sum;
              if( left.up > 0)
                sum = sum + (long long int)(left.right - left.left + 1)*left.up;
              if( right.up > 0)
                sum = sum + (long long int )(right.right - right.left + 1)*right.up;

        }
        void addupdate(long long int value)
        {
            up = up + (long long int)value;
        }
        bool haspendingupdate()
        {
            if( up > 0)
                return true;
            else
                return false;
        }
        void applypendingupdate()
        {
            sum = sum + (long long int)(right - left + 1)*up;
            up = (long long int )0;
        }
        long long int getpendingupdate()
        {
            return up;
        }

        int getValue()
        {
            return 0;
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
               nodes[stindex].assignLeaf();
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
        //printf("sum = %ld     left=  %d       right =  %d\n",nodes[stindex].sum , left,right);
    }
     void buildtemp(int stindex,int left,int right)
    {
       // nodes[stindex].left = left;
      //  nodes[stindex].right = right ;
        if(left == right)
        {
               nodes[stindex].up = 0;
               nodes[stindex].sum = 0;
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].up = 0;
        nodes[stindex].sum = 0;
        return ;
        //printf("sum = %ld     left=  %d       right =  %d\n",nodes[stindex].sum , left,right);
    }


    SegmentTreeNode query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            SegmentTreeNode result = nodes[stindex];
            if( result.haspendingupdate() == true)  // for lazy;
                 result.applypendingupdate();

            //printf("sum = %ld     left=  %d       right =  %d\n",result.sum ,result.left,result.right);
            return result;
          }

        SegmentTreeNode result;
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;
        if( lo > mid)
            result =  query(2*stindex+1,lo,hi);
        else if( hi <= mid)
            result =  query(2*stindex,lo,hi);
        else
        {
            SegmentTreeNode leftResult = query(2*stindex, lo, mid);
            SegmentTreeNode rightResult = query(2*stindex+1, mid+1, hi);
            result.left = leftResult.left;
            result.right = rightResult.right;
            result.merge(leftResult, rightResult);
        }
		if( nodes[stindex].haspendingupdate() == true)   // for lazy
        {
            result.addupdate(nodes[stindex].getpendingupdate());
            result.applypendingupdate();
           // printf("yo\n");
        }
       // printf("sum = %ld     left=  %d       right =  %d\n",result.sum ,result.left,result.right);
		return result;

    }


	// another one

        void update(int stindex, int lo, int hi,long int value)
        {
            if (nodes[stindex].left == lo && nodes[stindex].right == hi)
            {
                nodes[stindex].addupdate(value);
               // printf("upvalue = %d sum = %ld     left=  %d       right =  %d\n",nodes[stindex].up,nodes[stindex].sum ,nodes[stindex].left,nodes[stindex].right);
                return;
            }

            int mid = (nodes[stindex].left + nodes[stindex].right) / 2;
            if (lo > mid)
                update(2*stindex+1,lo,hi, value);
            else if (hi <= mid)
                update(2*stindex,lo,hi, value);
            else
            {
                update(2*stindex ,lo, mid, value);
                update(2*stindex+1,mid+1,hi, value);
            }
            nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
           // printf("sum = %ld     left=  %d       right =  %d\n",nodes[stindex].sum ,nodes[stindex].left,nodes[stindex].right);
        }
	int main()
	{
	    int t;
	    scanf("%d",&t);
	    while(t--)
        {
            int n,c;
            scanf("%d %d",&n,&c);
           // buildtemp(1,0,100000);
            buildTree(1,0,n-1);
            while( c--)
            {
                int a,b,c;
                long long int v;
                scanf("%d",&a);
                if( a == 0)
                {
                    scanf("%d %d %lld",&b,&c,&v);


                         //printf("%d %d\n",b,c);
                         update(1,b-1,c-1,v);

                }
                else
                {
                    scanf("%d %d",&b,&c);

                        // printf("%d %d\n",b,c);
                      SegmentTreeNode re = query(1,b-1,c-1);
                      printf("%lld\n",re.sum);

                }

            }
          //  buildtemp(1,0,n-1);
            nodes[0].up = 0;
            lp(i,0,524298)
            {
               nodes[i].up = 0;
           }
                  // nodes[i].sum = 0;
                 // nodes[i].left = 0;
                  // nodes[i].right = 0;

        }
        return 0;
	}

