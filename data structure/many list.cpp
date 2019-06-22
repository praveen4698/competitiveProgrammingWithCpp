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


    struct SegmentTreeNode
    {
        int left,right ;
        set<int> S;
        SegmentTreeNode() : left(0), right(0) {};// constructor
    };

    SegmentTreeNode nodes[800000];
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        if(left == right)
            return ;
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);

    }
    void query(int stindex,int lo,int hi,int value)
    {
       // printf("%d %d\n",lo,hi);
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
         {
             nodes[stindex].S.insert(value);
             return;
         }
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;
        if( lo > mid)
            query(2*stindex+1,lo,hi,value);
        else if( hi <= mid)
            query(2*stindex,lo,hi,value);
        else
        {   query(2*stindex, lo, mid,value);
            query(2*stindex+1, mid+1, hi,value);
        }
    }
     set<int> ans;
     void update(int stindex ,int index)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
            ans.insert(nodes[stindex].S.begin(),nodes[stindex].S.end());
            return;
        }
		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
            update(stindex*2, index);
        else
            update(stindex*2+1, index);


		    ans.insert(nodes[stindex].S.begin(),nodes[stindex].S.end());



	}
    int main()
    {
        int n,m;
        scan2(n,m)
        buildTree(1,0,n-1);
        while(m--)
        {
            int a;
            scan(a);
            if( a == 0)
            {
                int b,c,d;
                scan3(b,c,d);
                query(1,b-1,c-1,d);
            }
            else
            {
                int b;
                scan(b);
                update(1,b-1);
                cout<<ans.size();
                printf("\n");
                ans.clear();
            }
        }

    }
