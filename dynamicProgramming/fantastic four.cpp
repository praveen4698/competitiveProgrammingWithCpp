#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const ll lim = 2e6 + 10;
    const ll ten = 1e9;
    ll p;
    int mark[lim];
    vector<ll> square;
    vector<ll> factor[lim];
    bool check(ll n)
    {
        ll i = 1;
        while(i < n)
        {
            ll temp = n/i;
            if( temp%8 == (ll)7)
                return true;

            i = 4*i;
        }
        return false;
    }
    void pre_compute()
    {
        for(ll i = 0;i <= lim ;++i)
            square.pb((ll)i*i);
        sort(square.begin(),square.end());

        for(ll i = 0;i < lim ;++i)
            mark[i] = 0;
        for(ll i = 0 ;i <= 1000;++i)
        {
            for( ll j = 0 ;j <= 1000; ++j)
            {
                int index = i*i + j*j;
                if( mark[index] == 0)
                {   mark[index] = 2;
                    factor[index].pb((ll)i);
                    factor[index].pb((ll)j);

                }
            }
        }
    }
    struct SegmentTreeNode
    {
        int left,right ;
        ll counti ;
        ll first,second;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf( ll value)
        {
            counti = value;
            first = value;
            second = (ll)1;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            ll a = left.first;
            ll b = left.second;
            ll c =  right.first;
            ll d = right.second;
            if( (a*b)%p < ten && (c*d)%p < ten)
            {
                first = (a*b)%p;
                second = (c*d)%p;
            }
            else if( (a*c)%p < ten && (b*d)%p < ten)
            {
                first = (a*c)%p;
                second = (b*d)%p;
            }
            else if( (a*d)%p < ten && (c*b)%p < ten)
            {
                first = (a*d)%p;
                second = (c*b)%p;
            }
            else if( (((a*b)%p)*c)%p < ten && d%p < ten  )
            {
                first = (((a*b)%p)*c)%p;
                second = d%p;
            }
            else if( (((a*b)%p)*d)%p < ten && c%p < ten  )
            {
                first = (((a*b)%p)*d)%p;
                second = c%p;
            }
            else if( (((a*c)%p)*d)%p < ten && b%p < ten  )
            {
                first = (((a*c)%p)*d)%p;
                second = b%p;
            }
            else //if( (((b*c)%p)*d)%p < ten && a%p < ten  )
            {
                first = (((b*c)%p)*d)%p;
                second = a%p;
            }
            counti = (first*second)%p;
        }

    };
    SegmentTreeNode nodes[800000];
    ll A[100001];
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
     void update(int stindex ,int index, ll value)
	 {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].assignLeaf(value);
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index, value);
		else
			update(stindex*2+1, index, value);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}
	int main()
	{
	    vector<ll> answer;
	    int z;
	    scan(z);
	    pre_compute();

	    while(z--)
        {
            int n,q;
            scan2(n,q);
            scanf("%lld",&p);
            lp(i,0,n)
            {
                scanf("%lld",&A[i]);
            }
            buildTree(1,0,n-1);
            while(q--)
            {
                int a;
                scan(a);
                if( a == 1)
                {
                    int x;
                    ll y;
                    scan(x);
                    scanf("%lld",&y);
                    update(1,x-1,y);
                }
                else
                {
                    int x,y;
                    scan2(x,y);
                    SegmentTreeNode ans = query(1,x-1,y-1);


                    ll counti  = ans.counti;

                    int value = upper_bound(square.begin(),square.end(),counti) - square.begin();
                    while( counti < square[value])
                        value--;

                    while( check(counti - square[value]))
                    {
                        value = value -1;

                    }
                    answer.pb((ll)sqrt(square[value]));
                    counti = counti - square[value];
                   value = upper_bound(square.begin(),square.end(),counti) - square.begin();
                    while( counti < square[value])
                        value--;


                    ll index = counti - square[value];

                   if( index <= 2000000)
                   {


                        while( mark[index] != 2 )
                        {
                            value = value -1;
                            index = counti - square[value];

                        }
                   }
                    answer.pb((ll)sqrt(square[value]));

                    counti = counti - square[value];
                    if( mark[counti] == 2)
                    {   answer.pb(*(factor[counti].begin()));
                        answer.pb(*(factor[counti].begin()+1));}
                    else
                    {
                        answer.pb(0);
                        answer.pb(0);
                    }
                    for(int i = 0;i< 4;++i)
                        printf("%lld ",answer[i]);
                    printf("\n");
                    answer.clear();
                }
            }
        }
        return 0;
	}
