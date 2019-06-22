#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[100001];
    struct SegmentTreeNode
    {
        int left,right ;
        int bit[32],mini;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            mini = value;
            int i = 0;
            while(value)
            {
                bit[i] = value&1;
                value = value/2;
                i++;
            }
        }
        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            mini = min(left.mini,right.mini);
            lp(i,0,32)
                bit[i] = left.bit[i]|right.bit[i];
        }

    };
    SegmentTreeNode nodes[800000];
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
    }

    int  query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
            return nodes[stindex].mini;

        int mid = (nodes[stindex].left + nodes[stindex].right)/2;
        if( lo > mid)
            return query(2*stindex+1,lo,hi);
        else if( hi <= mid)
            return query(2*stindex,lo,hi);
        else
            return min(query(2*stindex, lo, mid),query(2*stindex+1, mid+1, hi));

    }
    void update2(int stindex, int lo, int hi,int value)
    {
            bool check = 0;
            lp(i,0,32)
            {

                if( nodes[stindex].bit[i] and !((value >> i)&1))
                {
                    check = 1;

                    break;
                }
            }

            if( check == 0)
                return;

            if (nodes[stindex].left == nodes[stindex].right)
            {
                lp(i,0,32)
                    nodes[stindex].bit[i] = nodes[stindex].bit[i] & ((value>>i)&1);
                nodes[stindex].mini = nodes[stindex].mini&value;

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
        int n,q;
        scan2(n,q);
        lp(i,0,n)
            scan(A[i]);
        buildTree(1,0,n-1);
        while(q--)
        {
            int a;
            scan(a);
            if( a == 0 )
            {
                int b,c;
                scan2(b,c);
                printf("%d\n",query(1,b-1,c-1));
            }
            else
            {
                int b,c,d;
                scan3(b,c,d);
                update2(1,b-1,c-1,d);
            }
        }
        return 0;
    }
