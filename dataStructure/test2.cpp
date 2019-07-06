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
        map<int,int> cont;
        int prefixvalue,prefixlen,suffixvalue,suffixlen;
        int len ;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            cont.clear();
            cont[1]++;
            prefixlen = 1;
            prefixvalue = value;
            suffixlen = 1;
            suffixvalue = value;
        }
        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            cont.clear();
            map<int,int>::iterator it;
            it = left.cont.begin();
            while(it != left.cont.end())
            {
                cont[it->first]+=it->second;
                ++it;
            }
            it = right.cont.begin();
            while(it != right.cont.end())
            {
                cont[it->first]+=it->second;
                ++it;
            }
            if(left.suffixvalue == right.prefixvalue)
            {
                cont[left.suffixlen]--;
                cont[right.prefixlen]--;
                cont[right.prefixlen+left.suffixlen]++;
            }
            if( left.prefixlen == (left.right-left.left + 1) && left.prefixvalue == right.prefixvalue)
            {
                prefixlen = left.prefixlen + right.prefixlen;
                prefixvalue = left.prefixvalue;
            }
            else
            {
                prefixlen = left.prefixlen;
                prefixvalue = left.prefixvalue;
            }
            if( right.suffixlen == (right.right-right.left+1) && left.suffixvalue == right.suffixvalue)
            {
                suffixlen = right.suffixlen + left.suffixlen;
                suffixvalue = right.suffixvalue;
            }
            else
            {
                suffixlen = right.suffixlen;
                suffixvalue = right.suffixvalue;
            }
        }

    };
    SegmentTreeNode nodes[800000];
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
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
    vector<int> ans;
    void query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
                ans.pb(stindex);
                return;
        }
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;

        if( lo > mid)
            query(2*stindex+1,lo,hi);
        else if( hi <= mid)
           query(2*stindex,lo,hi);
        else
        {
            query(2*stindex, lo, mid);
            query(2*stindex+1, mid+1, hi);
        }

		return;
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
            map<int,int> M;
            while(q--)
            {
                int a,b,c;
                scan3(a,b,c);
                ans.clear();
              //  query(1,a-1,b-1);
                M.clear();
                map<int,int>::iterator it;

               /* it = nodes[ans[0]].cont.begin();
                while(it != nodes[ans[0]].cont.end())
                {
                    M[it->first]+=it->second;
                    ++it;;
                }
                lp(i,1,ans.size())
                {
                    it = nodes[ans[i]].cont.begin();
                    while(it != nodes[ans[i]].cont.end())
                    {
                        M[it->first]+=it->second;
                        it++;
                    }
                    if( nodes[ans[i-1]].suffixvalue == nodes[ans[i]].prefixvalue )
                    {
                        M[nodes[ans[i-1]].suffixlen]--;
                        M[nodes[ans[i]].prefixlen]--;
                        M[nodes[ans[i-1]].suffixlen+nodes[ans[i]].prefixlen]++;
                    }
                }
                int conti = 0;
                it = M.begin();
                while(it!= M.end())
                {
                    //printf("%d %d\n",it->first,it->second);
                    if( it->first >= c)
                        conti+=it->second;

                    it++;
                }*/
                printf("0\n");



            }
        }
        return 0;
    }
