#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    #define mx  100005;
    int tree[800016][3];
    int lazy[800016];

    int swap1(int &a,int &b,int &c)
    {
        int ta = a,tb = b,tc = c;
        a = tc;
        b = ta;
        c = tb;
    }
    int swap2(int &a,int &b,int &c)
    {
        int ta = a,tb = b,tc = c;
        a = tb;
        b = tc;
        c = ta;
    }

    void build(int stindex,int left,int right)
    {
        lazy[stindex] = 0;
        if(left == right)
        {
            tree[stindex][0] = 1;
            tree[stindex][1] = 0;
            tree[stindex][2] = 0;
            return ;
        }

        int mid = (left + right)>>1;
        build(stindex<<1,left,mid);
        build(stindex<<1|1,mid+1,right);

        tree[stindex][0] = tree[stindex<<1][0] + tree[stindex<<1|1][0];
        tree[stindex][1] = 0;
        tree[stindex][2] = 0;
        return ;

    }

    void propagate(int stindex,int left ,int right)
    {

        if( left != right)
        {
            lazy[stindex<<1] = (lazy[stindex] + lazy[stindex<<1])%3;
            lazy[stindex<<1|1] = (lazy[stindex] + lazy[stindex<<1|1])%3;

        }

        if(lazy[stindex] == 1)
        {
            swap1( tree[stindex][0],tree[stindex][1],tree[stindex][2]);
        }

        if(lazy[stindex] == 2)
        {
            swap2(tree[stindex][0],tree[stindex][1],tree[stindex][2]);
        }

        lazy[stindex] = 0;
    }

    int query(int stindex,int left,int right ,int start,int end)
    {

        if( lazy[stindex])
            propagate(stindex,left,right);

        if( left > end || right <start)
            return 0;

        if( start <= left && right <= end)
        {
            return tree[stindex][0];

        }

        int mid = (left + right) >>1;
        return ( query(stindex*2,left,mid,start,end) + query(stindex*2+1,mid+1,right,start,end));
    }

    void update(int stindex,int left,int right,int start,int end)
    {
        if( lazy[stindex])
            propagate(stindex,left,right);

        if( left > end || right <start)
            return ;

        if( start <= left && right <= end)
        {
            if(left != right)
            {
                lazy[2*stindex] = (1+ lazy[2*stindex])%3;
                lazy[2*stindex + 1] = (1+ lazy[2*stindex+1])%3;
            }
            swap1(tree[stindex][0],tree[stindex][1],tree[stindex][2]);
            return ;
        }

        int mid = (left+right)/2;
        update(stindex*2,left,mid,start,end);
        update(stindex*2+1,mid+1,right,start,end);

        tree[stindex][0] = tree[2*stindex][0] + tree[2*stindex+1][0];
        tree[stindex][1] = tree[2*stindex][1] + tree[2*stindex+1][1];
        tree[stindex][2] = tree[2*stindex][2] + tree[2*stindex+1][2];
    }
    int main()
    {
        int T  ,i , q ,n;

        scanf("%d %d",&n,&q);

        build(1,1,n);

        while( q-- )
        {
            int typ , x , y;
            scanf("%d %d %d",&typ,&x,&y);
            x++,y++;
            if( typ == 0)
            {
                update(1,1,n,x,y);
            }
            else if( typ == 1)
            {
                int ans = query(1,1,n,x,y);
                printf("%d\n",ans);
            }
        }

        return 0;
    }
