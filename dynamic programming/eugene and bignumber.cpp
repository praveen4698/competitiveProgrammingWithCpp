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

    ll A[14],counti;
    ll  solve(ll a,ll n, ll m)
    {
        if(  n == 1)
            return (a%m);

        ll temp = solve(a,n/2,m);
        printf("temp = %lld n == %lld\n",temp,n/2);
        ll tem = temp ;
        temp = temp*temp;
        temp = temp%m;
        if( n%2 == 1)
        {
            lpr(i,counti-1,0)
            {
                temp = temp*10 + A[i];
                temp = temp%m;

            }

        }

   /*     ll te[14] ;
        ll counti_2 = 0;
        while(tem > 0)
        {
            te[counti_2] = (ll)tem%10;
            tem = tem/10;
            counti_2++;

        }
        lpr(i,counti_2-1,0)
        {
            temp = temp*10 + (ll)te[i];
            temp = temp%m;
            printf("te[%d] = %lld ",i,te[i]);
        }
        printf("\ncounti_2 = %lld\n",counti_2);*/

        return temp;
    }
    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            ll a,n,m;
            cin>>a;
            cin>>n;
            cin>>m;
            counti = 0;
            ll a1 = a;
            while( a1 > 0)
            {
                A[counti] = a1%10;
                a1 = a1/10;
                counti++;

            }

            printf("%lld\n",solve(a,n,m)%m);
        }
        return 0;
    }
