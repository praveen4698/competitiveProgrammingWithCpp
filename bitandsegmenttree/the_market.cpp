#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    int A[lim],cost[lim];
    vector<int> primes[lim];
    void preprocess()
    {
         for ( int i = 1; i <= 1000000; i++ ) {
        for ( int j = i; j <= 1000000; j += i ) cost[j]++;
            }
    }
    void preprocess1()
    {
        memset(A,0,sizeof(A));
        memset(cost,0,sizeof(cost));
        for(int i=2;i<lim;++i)
        {
            if(A[i] == 0)
            {
                primes[i].push_back(i);
                for(int j=2*i;j<lim;j=j+i)
                {
                    A[j] = 1;
                    primes[j].push_back(i);
                }
            }
        }
        cost[1] = 1;
        for(int i=2;i<lim;++i)
        {
            int ans = 1;
            int j = i;
            for(auto p:primes[i])
            {
                int t = 0;
                while(j%p == 0)
                {
                    t++;
                    j = j/p;
                }
                ans*=(t+1);
            }
            cost[i] = ans;
        }
    }
        struct TNode
    {
        int l,r ;
        unordered_map<int,int> M;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            M[cost[value]]++;
        }

        void merge(TNode& left, TNode& right)
        {
            for(auto a:left.M)
                M[a.first]+=a.second;
            for(auto a:right.M)
                M[a.first]+=a.second;
        }

    };

    TNode nodes[800000];
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
    unordered_map<int,int> ans;
    void query(int st,int lo,int hi)
    {

        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            for(auto a:nodes[st].M)
                ans[a.first]+=a.second;
            return ;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        //TNode res;
        if( lo > mid)
             query(2*st+1,lo,hi);
        else if( hi <= mid)
            query(2*st,lo,hi);
        else
        {
            query(2*st, lo, mid);
            query(2*st+1, mid+1, hi);

        }
		//return res;

    }
    inline int readint()
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
        preprocess();
      /*  int maxi = 0;
        map<int,int> tt;
        int re = -1;
        for(int i=0;i<lim;++i)
         {
             tt[cost[i]]++;
           if( maxi < cost[i])
            {

                maxi = cost[i];
                re = i;
            }
         }
        cout<<maxi<<endl;
        cout<<tt.size()<<endl;*/
        int n;
        n = readint();
        for(int i=0;i<n;++i)
            A[i] = readint();
        buildTree(1,0,n-1);
        int q;
        q = readint();
        while(q--)
        {
            int a,b;
            a = readint();
            b = readint();
            ans.clear();
            query(1,a-1,b-1);
            ll res = 0ll;
            for(auto a:ans)
                res = res + ((a.second)*1ll*(a.second-1))/2;
            cout<<res<<endl;
        }
        return 0;
    }
