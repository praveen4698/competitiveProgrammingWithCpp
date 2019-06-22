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

    pair<int,int> store[1000001];
    struct SegmentTreeNode
    {
        int left,right ;
        vi A;
        int sum ,limit;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
                sum = value;

        }



    };

    SegmentTreeNode nodes[8000000];
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        nodes[stindex].limit = right - left + 1;
        if(left == right)
        {
               nodes[stindex].assignLeaf(0);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].sum = 0;
    }

    void query(int stindex,int lo,int hi,int num)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            nodes[stindex].A.push_back(num);
            if(nodes[stindex].sum == nodes[stindex].limit)
            {
                store[num].F = store[num].F + nodes[stindex].sum;

            }
            return ;
        }
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;

        if( lo > mid)
            query(2*stindex+1,lo,hi,num);
        else if( hi <= mid)
            query(2*stindex,lo,hi,num);
        else
        {
            query(2*stindex, lo, mid,num);
            query(2*stindex+1, mid+1, hi,num);
        }



    }

    int ans = 0;
    void update(int stindex ,int index)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].sum = 1;
			if( nodes[stindex].sum == nodes[stindex].limit)
            {
                vector<int>::iterator it;
                for(it = nodes[stindex].A.begin();it != nodes[stindex].A.end(); ++it)
                {
                    store[*it].F = store[*it].F + 1;
                    if(store[*it].F == store[*it].S)
                        ans++;
                }
            }
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index);
		else
			update(stindex*2+1, index);

		nodes[stindex].sum = nodes[2*stindex].sum + nodes[2*stindex + 1].sum;

		if( nodes[stindex].sum == nodes[stindex].limit)
            {
                vector<int>::iterator it;
                for(it = nodes[stindex].A.begin();it != nodes[stindex].A.end(); ++it)
                {
                    store[*it].F = store[*it].F + nodes[stindex].limit;
                    if(store[*it].F == store[*it].S)
                        ans++;
                }
            }
	}

	int main()
	{
	    int n,q;
	    scan2(n,q);
	    buildTree(1,1,n);
	    lp(i,0,q)
	    {
	        store[i].F = 0;
	        store[i].S = 0;
	    }
	    lp(i,0,q)
	    {
	        int a,b,c;
	        scan(a);
	        if( a == 0)
            {
                scan2(b,c);
                store[i].S = c- b + 1;
                query(1,b,c,i);
                fflush(stdout);

            }
            else
            {
                scan(b);
                ans = 0;
                update(1,b);
                printf("%d\n",ans);
                fflush(stdout);
            }
	    }

	}
