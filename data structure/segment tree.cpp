#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int st[1024];
    int A[512];
    int lazy[1024];
    void buildst(int l,int r,int stindex)
    {
        if(l == r)
        {
            st[stindex] = A[l];
            return ;
        }

        int mid = (l+r)/2;
        buildst(l,mid,2*stindex);
        buildst(mid+1,r,2*stindex+1);

        st[stindex] = min( st[2*stindex] , st[2*stindex+1]);
        return ;
    }

    int solve(int l,int r, int stindex,int low ,int high)
    {
        if( l == low && r == high)
            return st[stindex];

        int mid = (low+high)/2;

        if( mid >= r)
            return solve(l,r,2*stindex,low,mid);
        else if( mid < l)
            return solve(l,r,2*stindex+1,mid+1,high);

        int leftresult = solve(l,mid,2*stindex,low,mid);
        int rightresult = solve(mid+1,r,2*stindex,mid+1,high);

        return min(leftresult,rightresult);

    }
    // low-high is the range segment tree node represent
    // l-r range to be updated
    void update_tree(int low ,int high,int stindex,int l,int r,int value)
    {

        if(lazy[stindex]  != 0)
        {
            st[stindex]+=lazy[stindex];
            if( low!=high)
            {
                lazy[2*stindex]+=lazy[stindex];
                lazy[2*stindex+1]+=lazy[stindex];
            }
            lazy[stindex] = 0;
        }

        if( low>high || low > r || high<l)
            return ;

        if( low >= l && high <= r)
        {
            st[stindex]+=value;
            if( low!=high)
            {
                lazy[2*stindex]+=value;
                lazy[2*stindex + 1]+=value;
            }

            return ;
        }

        int mid = (low+high)/2;
        update_tree(low,mid,2*stindex,l,r,value);
        update_tree(mid+1,high,2*stindex+1,l,r,value);

        st[stindex] = min(st[2*stindex],st[2*stindex+1]);
        return ;

    }


    int main()
    {
        int n;
        printf("enter the number of elements: ");
        scanf("%d",&n);
        printf("enter the elements : ");
        loop(i,0,n)
        {
            scanf("%d",&A[i]);
        }
        buildst(0,n-1,1);
        loop(i,0,2*n)
        {
            printf("%d\n",st[i]);
        }
        printf("enter the number of query : ");
        int q;
        scanf("%d",&q);
        loop(i,0,q)
        {
            int a,b;
            cin>>a>>b;
            printf("\n the minimum is : %d\n",solve(a,b,1,0,n-1));
        }
        update_tree(0,7,1,1,1,-15);
        update_tree(0,7,1,6,7,-79);
        loop(i,0,2*n)
        {
            printf("%d\n",st[i]);
        }

        return 0;
    }
