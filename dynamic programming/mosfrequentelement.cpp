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
    const int lim = 1e5 + 10;
    int A[lim];
    struct SegmentTreeNode
    {
        int left,right ;
        int maxi,maxivalue,suffixmaxi,suffixvalue,prefixmaxi,prefixvalue;
        int mark;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            maxi = suffixmaxi = prefixmaxi = 1;
            maxivalue = suffixvalue = prefixvalue = value;
            mark = -1;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            int n1 = left.right - left.left + 1;
            if( left.prefixvalue == left.suffixvalue && left.suffixvalue == right.prefixvalue && left.prefixmaxi == n1)
            {
                prefixvalue = left.prefixvalue;
                prefixmaxi = left.prefixmaxi + right.prefixmaxi;
            }
            else
            {
                prefixmaxi = left.prefixmaxi;
                prefixvalue = left.prefixvalue;
            }
            int n2 = right.right - right.left + 1;
            if( right.suffixvalue == right.prefixvalue && left.suffixvalue == right.suffixvalue && right.suffixmaxi == n2)
            {
                suffixvalue = right.suffixvalue;
                suffixmaxi = right.suffixmaxi + left.suffixmaxi;
            }
            else
            {
                suffixmaxi = right.suffixmaxi;
                suffixvalue = right.suffixvalue;
            }

            int temp = 0;
            int tempvalue = -2;
            if( left.suffixvalue == right.prefixvalue)
            {
                temp = left.suffixmaxi + right.prefixmaxi;
                tempvalue = left.suffixvalue;
            }
            if( left.maxi >= right.maxi && left.maxi >= temp)
            {
                maxi = left.maxi;
                maxivalue = left.maxivalue;
            }
            else if( right.maxi >= left.maxi && right.maxi >= temp)
            {
                maxi = right.maxi;
                maxivalue = right.maxivalue;
            }
            else if( temp > right.maxi && temp > left.maxi)
            {
                maxi = temp;
                maxivalue = tempvalue;
            }
        }

    };
    SegmentTreeNode nodes[1000000];

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
    SegmentTreeNode querylazy(int stindex,int lo,int hi)
    {


        if(nodes[stindex].left > hi || nodes[stindex].right < lo)
            return nodes[0];

        if( nodes[stindex].left >= lo && nodes[stindex].right <= hi)
        {
            return nodes[stindex];

        }
        SegmentTreeNode lr = querylazy(2*stindex,lo,hi);
        SegmentTreeNode  rr =  querylazy(2*stindex+1,lo,hi);
        SegmentTreeNode result ;
        result.left = lr.left;
        result.right = rr.right;
        if( lr.mark == -2)
            return rr;
        if( rr.mark == -2)
            return lr;

        result.merge(lr,rr);
        return result;
    }
    int main()
    {
        int n,q;
        scan2(n,q);
        lp(i,0,n)
            scan(A[i]);
        buildTree(1,0,n-1);
        nodes[0].mark = -2;
        while(q--)
        {
            int a,b,k;
            scan3(a,b,k);
            SegmentTreeNode ans = querylazy(1,a-1,b-1);
          //  printf("%d %d\n",ans.maxi,ans.maxivalue);
            if( ans.maxi >= k)
                printf("%d\n",ans.maxivalue);
            else
                printf("-1\n");

        }
        return 0;
    }
