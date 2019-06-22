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
        int A[10],up;
        SegmentTreeNode() :up(0),left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            lp(i,0,10)
                A[i] = 0;
            A[value] = 1;

            up = 0;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {

            lp(i,0,10)
                A[i] = left.A[i] + right.A[i];


        }
        void propagate()
        {
            int temp = A[9];
            lpr(i,9,1)
                A[i] = A[i-1] ;
            A[0] = temp;

        }
        void querypropagate(int value)
        {
            int temp[10];
            lp(i,0,10)
                temp[i] = A[i];
            lp(i,0,10)
                A[(i+value)%10] = temp[i];


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
               nodes[stindex].assignLeaf(0);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }

    int query(int stindex,int lo,int hi)
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


        void update(int stindex, int lo, int hi)
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
        int main()
        {
            int n,m;
            scanf("%d %d",&n,&m);
            buildTree(1,0,n-1);
            while(m--)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                if(a == 1)
                {
                    update(1,b-1,c-1);
                }
                else
                {

                    printf("%d\n",query(1,b-1,c-1));
                }

            /*    lp(i,1,10)
                {
                    printf("node no  == %d ,update == %d\n" ,i,nodes[i].up);
                    lp(j,0,10)
                    {
                        printf("A[%d] = %d,",j,nodes[i].A[j]);
                        if( j== 4)
                            printf("\n");
                    }
                    printf("\n\n\n");
                }*/
            }
            return 0;
        }
