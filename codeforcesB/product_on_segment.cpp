#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6+10;
const int logn = 20;
ll sparse_table[lim][logn];
ll A[lim];
ll B[lim];
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,q;
        ll p;
        scan(n);
        scanf("%lld",&p);
        scan(q);
        for(int i=0;i<n;++i)
            scanf("%lld",&A[i]);
        int cont = ( q >> 6) + 2;
        //cout<<cont<<endl;
        for(int i=0;i<cont;++i)
            scanf("%lld",&B[i]);
        for(int i=0;i<n;++i)
            sparse_table[i][0] = A[i]%p;
        for(int k=1;k<logn;++k)
        {
            if( 1<<k >= n)
                continue;
            for(int i=0;i<n;++i)
            {
                int x = i+(1<<(k-1));
                sparse_table[i][k] = ((sparse_table[i][k-1])*(sparse_table[x][k-1]))%p;

            }
        }
        ll prevans = 0;
        ll li=0,ri= 0;
        for(int i=0;i<q;++i)
        {
            if( i%(64) == 0)
            {
                li = B[(i/64)];
                ri = B[(i/64) + 1];
            }
            li = (li + prevans)%n;
            ri = (ri + prevans)%n;
            if( li > ri)
                swap(li,ri);
            ll temp = 1;
            /*for(int j=li;j<=ri;++j)
            {
                temp*=A[j];
                temp%=p;
            }*/
            cout<<li<<" "<<ri<<endl;
            int diff = ri-li+1;
            for(int j=logn-1;j>=0;--j)
            {
                if( diff&(1<<j))
                {
                    temp*=sparse_table[li][j];
                    temp%=p;

                    li = li + (1<<j) - 1;
                    cout<<li<<endl;
                }

            }
            prevans = (temp+1ll)%p;

        }
        cout<<prevans<<endl;

    }
    return 0;
}


