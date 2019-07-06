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
        int dominant;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            cont.clear();
            cont[value]++;
            dominant = value;
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
            if(cont[left.dominant] > (right.right-left.left+1)/2)
                 dominant = left.dominant;
            else if(cont[right.dominant] > (right.right-left.left+1)/2)
                dominant = right.dominant;
            else
                dominant = -1;
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
    void update(int stindex ,int index, int value,int oldvalue)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].assignLeaf(value);
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index, value,oldvalue);
		else
			update(stindex*2+1, index, value,oldvalue);
        int len = nodes[stindex].right - nodes[stindex].left + 1;
		//nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
		nodes[stindex].cont[oldvalue]--;
		nodes[stindex].cont[value]++;
		if(nodes[stindex].cont[nodes[2*stindex].dominant] > len/2)
            nodes[stindex].dominant = nodes[2*stindex].dominant;
        else if( nodes[stindex].cont[nodes[2*stindex+1].dominant] > len/2)
            nodes[stindex].dominant = nodes[2*stindex+1].dominant;
        else
            nodes[stindex].dominant = -1;
		return;
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
            int a,b,c;
            scan3(a,b,c);
            if( a == 1)
            {
                update(1,b-1,c,A[b-1]);
                A[b-1] = c;
            }
            else
            {
                ans.clear();
                query(1,b-1,c-1);
                int found = -1;
                int len = c-b+1;
                lp(i,0,ans.size())
                {
                    int cont = 0;
                    lp(j,0,ans.size())
                    {
                        cont+=(nodes[ans[j]].cont[nodes[ans[i]].dominant]);
                    }
                    if(cont > len/2)
                    {
                        found = 1;
                        break;
                    }
                }
                if(found == 1)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
        return 0;
    }
