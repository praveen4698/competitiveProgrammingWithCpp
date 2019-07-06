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
        int lefti,righti ;
        int *G,*sum;
        int prefixvalue,prefixlen,suffixvalue,suffixlen;
        int len ;
        SegmentTreeNode() : lefti(0), righti(0) {};// constructor

        void assignLeaf(int value)
        {
            prefixlen = suffixlen = 1;
            prefixvalue = suffixvalue = value;
            len = 2;
            G = new int[len];
            sum = new int[len];
            G[1] = 1;
            sum[1] = 1;

        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            len = righti - lefti + 3;
            G = new int[len];
            sum = new int[len];
            lp(i,0,len)
                {
                    sum[i] = G[i] = 0;
                }
            lp(i,0,left.len)
                G[i] = G[i] + left.G[i];
            lp(i,0,right.len)
                G[i] =  G[i] + right.G[i];

            if( left.suffixvalue == right.prefixvalue)
            {
                G[left.suffixlen]--;
                G[right.prefixlen]--;
                G[left.suffixlen + right.prefixlen]++;
            }
            if( left.prefixlen == (left.righti-left.lefti + 1) && left.prefixvalue == right.prefixvalue)
            {
                prefixlen = left.prefixlen + right.prefixlen;
                prefixvalue = left.prefixvalue;
            }
            else
            {
                prefixlen = left.prefixlen;
                prefixvalue = left.prefixvalue;
            }
            if( right.suffixlen == (right.righti-right.lefti+1) && left.suffixvalue == right.suffixvalue)
            {
                suffixlen = right.suffixlen + left.suffixlen;
                suffixvalue = right.suffixvalue;
            }
            else
            {
                suffixlen = right.suffixlen;
                suffixvalue = right.suffixvalue;
            }

            sum[len-1] = G[len-1];
            lpr(i,len-2,1)
                sum[i] = sum[i+1] + G[i];
        }

    };
    SegmentTreeNode nodes[8000000];
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].lefti = left;
        nodes[stindex].righti = right ;
       // printf("%d %d %d\n",stindex,left,right);
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
    struct Node
    {
        int cont;
        int prefix,suffix,lenprefix,lensuffix;
        };
    Node query(int stindex,int lo,int hi,int c)
    {
        if(nodes[stindex].lefti == lo && nodes[stindex].righti == hi)
        {
            Node result;
            if( c <= (nodes[stindex].righti - nodes[stindex].lefti +1))
             {
                 result.cont = nodes[stindex].sum[c];
             }
            else
            {
                result.cont =0;
            }
            result.prefix = nodes[stindex].prefixvalue;
            result.lenprefix = nodes[stindex].prefixlen;
            result.suffix = nodes[stindex].suffixvalue;
            result.lensuffix = nodes[stindex].suffixlen;
            return result;
        }
        int mid = (nodes[stindex].lefti + nodes[stindex].righti)/2;
        Node result;
        if( lo > mid)
            result = query(2*stindex+1,lo,hi,c);
        else if( hi <= mid)
            result = query(2*stindex,lo,hi,c);
        else
        {
            Node leftResult = query(2*stindex, lo, mid,c);
            Node rightResult = query(2*stindex+1, mid+1, hi,c);

            //result.merge(leftResult, rightResult);
            result.cont = leftResult.cont + rightResult.cont;
            if( leftResult.suffix == rightResult.prefix )
            {
                if(leftResult.lensuffix >= c)
                    result.cont--;
                if(rightResult.lenprefix >= c)
                    result.cont--;
                if(leftResult.lensuffix + rightResult.lenprefix >= c )
                    result.cont++;
            }
            if( leftResult.prefix == rightResult.prefix &&
                leftResult.lenprefix == (nodes[2*stindex].righti - nodes[2*stindex].lefti+1))
            {
                result.prefix = leftResult.prefix;
                result.lenprefix = leftResult.lenprefix + rightResult.lenprefix;
            }
            else
            {
                result.prefix = leftResult.prefix;
                result.lenprefix = leftResult.lenprefix ;
            }
            if( rightResult.suffix == leftResult.suffix &&
               rightResult.lensuffix == (nodes[2*stindex+1].righti - nodes[2*stindex+1].lefti +1))
            {
                result.suffix = rightResult.suffix;
                result.lensuffix = leftResult.lensuffix + rightResult.lensuffix;

            }
            else
            {
                result.suffix = rightResult.suffix;
                result.lensuffix = rightResult.lensuffix;
            }
        }
		return result;

    }
    int main()
    {
        int t;
        scan(t);
        lp(j,0,t)
        {
            int n,q;
            scan2(n,q);
            lp(i,0,n)
                scan(A[i]);
            buildTree(1,0,n-1);
            while(q--)
            {
                int a,b,c;
                scan3(a,b,c);
                Node res = query(1,a-1,b-1,c);
                printf("%d\n",res.cont);
            }
        }
        return 0;
    }
