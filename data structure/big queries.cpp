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

    int A[100001];
    struct division
    {
        int two;
        int five;
        division(): two(0),five(0) {};
    };
    division divi[100001];
    void create()
    {
        lp(i,1,100001)
        {
            int value = i,count2 = 0,count5 = 0;
            while( value%2 == 0)
            {
                value = value/2;
                count2 = count2 +1;
            }
            while(value%2 == 0)
            {
                value = value/5;
                count5 = count5 + 1;
            }
            divi[i].two = divi[i-1].two + count2;
            divi[i].five = divi[i-1].five + count5;

        }
    }
    struct SegmentTreeNode
    {
        int left,right ;
        int two,five,upfive,uptwo;
        int zeros;
        int y ;
        SegmentTreeNode() :two(0),five(0),zeros(0), left(0), right(0),upfive(0),uptwo(0),y(0) {};// constructor

        void assignLeaf(int value)
        {

            while( value%2 == 0)
            {
               // printf("y2\n");
                value = value/2;
                two = two + 1;
            }
            while( value%5 == 0)
            {
              //  printf("y5\n");
                value = value/5;
                five = five + 1;
            }
            zeros = min(two,five);
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
              five = left.five + right.five + (left.right - left.left + 1)*(left.upfive) + (right.right - right.left + 1)*right.upfive;
              two = left.two + right.two +(left.right - left.left + 1)*(left.uptwo) + (right.right - right.left + 1)*right.uptwo ;
              zeros = min( five,two);
        }
        void addupdate(int count2,int count5)
        {
               uptwo = uptwo + count2;
               upfive = upfive + count5;
        }
        bool haspendingupdate()
        {
             return false;
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
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;

        if(left == right)
        {
               nodes[stindex].assignLeaf(A[left]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
       // printf(" zeros = %d left =  %d right = %d \n",nodes[stindex].zeros,left , right);
    }

    SegmentTreeNode query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            SegmentTreeNode result = nodes[stindex];
            result.five = result.five + (result.right - result.left + 1)*result.upfive;
            result.two = result.two + (result.right - result.left + 1)*result.uptwo;
            result.zeros = min( result.five , result.two);
           // printf("result zeros %d left = %d right = %d\n",result.zeros,lo,hi);
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
        result.five = result.five + (result.right - result.left + 1)*nodes[stindex].upfive;
        result.two = result.two + (result.right - result.left + 1)*nodes[stindex].uptwo;
       // printf("result zeros %d left = %d right = %d\n",result.zeros,lo,hi);
        result.zeros = min( result.five , result.two);
       // printf("result zeros %d left = %d right = %d\n\n",result.zeros,lo,hi);
		return result;

    }
    void partailupdate(int stindex,int count2,int count5)
    {

                count5 = count5 + nodes[stindex].upfive;
                count2 = count2 + nodes[stindex].uptwo;
                nodes[stindex].five = count5 + nodes[stindex].five;
                nodes[stindex].two = count2 + nodes[stindex].two;
                nodes[stindex].uptwo = 0;
                nodes[stindex].upfive = 0;
                nodes[stindex].zeros = min( nodes[stindex].two,nodes[stindex].five);
                if(nodes[stindex].left == nodes[stindex].right)
                    return ;
                partailupdate(stindex*2,count2,count5);
                partailupdate(stindex*2+1,count2,count5);


    }
    void finalupdate(int stindex ,int lo,int hi,int y,int left ,int right)
    {

        if( nodes[stindex].left == nodes[stindex].right)
        {
            int count2=0,count5=0;
            nodes[stindex].y = y;
            while( y%2 == 0)
            {
                y = y/2;
                count2 = count2 +1;
            }
            while( y%5 == 0)
            {
                y = y/5;
                count5 = count5 + 1;
            }
            nodes[stindex].five = divi[right].five - divi[left-1].five + count5;
            nodes[stindex].two = divi[right].two - divi[left-1].two + count2;
            nodes[stindex].upfive = 0;
            nodes[stindex].uptwo = 0;
           // nodes[stindex].mark = 1;
            nodes[stindex].zeros = min( nodes[stindex].five,nodes[stindex].two);
            return ;
        }

        int mid = (nodes[stindex].left + nodes[stindex].right)/2;

            if (lo > mid)
                finalupdate(2*stindex+1,lo,hi,y,left,right);
            else if (hi <= mid)
                finalupdate(2*stindex,lo,hi,y,left,right);
            else
            {
                int temp = mid-lo;
                finalupdate(2*stindex ,lo, mid,y,left,left+temp);
                finalupdate(2*stindex+1,mid+1,hi,y,left+temp+1,right);
            }
            nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);


    }

    void finalupdate2(int stindex ,int index, int y,int value)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
            int count2=0,count5=0;
            nodes[stindex].y = y;
            while( y%2 == 0)
            {
                y = y/2;
                count2 = count2 +1;
            }
            while( y%5 == 0)
            {
                y = y/5;
                count5 = count5 + 1;
            }
            nodes[stindex].five = divi[value].five - divi[value-1].five + count5;
            nodes[stindex].two = divi[value].two - divi[value-1].two + count2;
            nodes[stindex].uptwo = 0;
            nodes[stindex].upfive = 0;
            nodes[stindex].zeros = min( nodes[stindex].five,nodes[stindex].two );
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			finalupdate2(stindex*2, index, y,value);
		else
			finalupdate2(stindex*2+1, index,y, value);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}

	// another one

        void update2(int stindex, int lo, int hi,int value)
        {
            if (nodes[stindex].left == lo && nodes[stindex].right == hi)
            {
                int count2 = 0;
                int count5 = 0;
                while( value%2 == 0)
                {
                    count2 = count2 + 1;
                    value = value/2;
                }
                while(value%5 == 0)
                {
                    count5 = count5 + 1;
                    value = value/5;
                }
             //   printf("%d %d\n",count2,count5);
                nodes[stindex].addupdate(count2,count5);
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

     int main()
     {
         int Z;
         scanf("%d",&Z);
         create();
         while(Z--)
         {
             int n,m;
             scanf("%d %d",&n,&m);
             lp(i,0,n)
             {
                 scanf("%d",&A[i]);
             }
             buildTree(1,0,n-1);
             int ans = 0;
             while(m--)
             {
                 int a,b,c;
                 scanf("%d %d %d",&a,&b,&c);
                 if( a == 3)
                 {
                     SegmentTreeNode re = query(1,b-1,c-1);
                   // printf("%d %d %d\n",re.zeros, re.five,re.two);
                    ans = ans + re.zeros;
                 }
                 if( a == 1)
                 {
                     int X;
                     scanf("%d",&X);
                     update2(1,b-1,c-1,X);
                 }
                 if( a == 2)
                 {
                     int y;
                     scanf("%d",&y);
                     partailupdate(1,0,0);
                     lp(i,b-1,c)
                        finalupdate2(1,i,y,i-b+2);
                 }
              //   for(int i = 1;i < 10;++i)
              //   {
               //      printf("five = %d two = %d upfive = %d uptwo = %d\n",nodes[i].five,nodes[i].two,nodes[i].upfive,nodes[i].uptwo);
               //  }
             }
             printf("%d\n",ans);
             for(int i = 0;i< 262200;++i)
             {
                 nodes[i].upfive = 0;
                 nodes[i].uptwo = 0;
                 nodes[i].two = 0;
                 nodes[i].five = 0;
                 nodes[i].zeros = 0;
                 nodes[i].y = 0;
                 nodes[i].left = 0;
                 nodes[i].right = 0;

             }
         }
         return 0;
     }
