#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    struct TNode
    {
        int l,r ;
        int left_element,right_element,left_subarray,right_subarray,maxi;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            left_element = value;
            right_element = value;
            right_subarray = 1;
            left_subarray = 1;
            maxi = 1;
        }

        void merge(TNode& left, TNode& right)
        {
            maxi = max(left.maxi,right.maxi);
            if(left.right_element+1==right.left_element)
                maxi = max(maxi,left.right_subarray+right.left_subarray);

            left_element = left.left_element;
            left_subarray = left.left_subarray;
            int len = left.r - left.l + 1;
            if(left.left_subarray == len && left.right_element+1==right.left_element)
                left_subarray+=right.left_subarray;
            right_element = right.right_element;
            right_subarray = right.right_subarray;
            len = right.r - right.l + 1;
            if(right.right_subarray == len && left.right_element+1==right.left_element)
                right_subarray+=(left.right_subarray);
        }

    };

    TNode nodes[400000];
    int A[lim];
    void buildTree(int st,int lo,int hi)
    {
        nodes[st].l = lo;
        nodes[st].r = hi ;
        if(lo == hi)
        {
               nodes[st].assignLeaf(A[lo]);
               return ;
        }
        int mid = (lo + hi)>>1;
        buildTree(st<<1,lo,mid);
        buildTree(st<<1|1,mid+1,hi);
        nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
    }
    void update(int st ,int index, int value)
	 {

		if (nodes[st].l == nodes[st].r)
        {
			nodes[st].assignLeaf(value);
			return;
		}

		int  mid = (nodes[st].l + nodes[st].r)>>1;
		if (index <= mid)
			update(st<<1, index, value);
		else
			update(st<<1|1, index, value);

		nodes[st].merge(nodes[st<<1], nodes[st<<1|1]);
	}
	inline int read()
    {
        int x=0,f=1;
        char ch=getchar();
        while(ch<'0'||ch>'9')
        {
            if(ch=='-')
                f = -1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9')
        {
            x=x*10+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    int main()
    {
        int n,q;
       // scanf("%d %d",&n,&q);
        n = read();
        q = read();
        for(int i=0;i<n;++i)
        {
           // scanf("%d",&A[i]);
            A[i] = read();
        }
        buildTree(1,0,n-1);
        printf("%d\n",nodes[1].maxi);
        while(q--)
        {
            int x,y;
           // scanf("%d %d",&x,&y);
            x = read();
            y = read();
            update(1,x-1,y);
            printf("%d\n",nodes[1].maxi);
        }
        return 0;
    }
