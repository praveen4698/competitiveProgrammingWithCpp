#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sc(x) scanf("%d",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define scl(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld%lld",&x,&y);
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);

#define pb push_back
#define mp make_pair

#define M 1000000007
#define inf 99999999999999999LL	//long long inf

#define debug(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define debug4(x,y,z,a) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#a<<" :: "<<a<<"\n";

#define LIM 50000
// 4:20pm
int n ;
ll a[LIM+4] ,fact[ LIM+4 ],inv[LIM+4];
ll powd(ll base, ll exp,ll mod) {
    ll res=1;

    while(exp>0) {
       if(exp&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
void pre()
{
	int i , j ;
	fact[0] = 1 ;
	for(i=1;i<=LIM;i++)
		fact[i] = (fact[i-1]*i)%M ;
	inv[ LIM ] = powd( fact[LIM] ,M-2,M);
	for(i = LIM-1;i>=0;i--)
		inv[ i ] = (inv[i+1]*(i+1))%M;
}
ll ncr( int n ,int r )
{
	if( n< r )
		return 0;
	return (((fact[ n ]*inv[r])%M) *inv[n-r] )%M ;
}
ll two[50000];
int main()
{
	int t;
	sc(t);
	pre();
	two[0] = 1;
	for(int i=1;i<50000;++i)
        two[i] = 2ll*two[i-1]%M;
	while(t--)
	{

		int n,q;
		scanf("%d %d",&n,&q);
		while(q--)
        {
            int i,k;

            scanf("%d %d",&i,&k);
            if( i<k)
            {
                printf("0\n");
                continue;
            }
            printf("%lld\n",two[n-i]*ncr(i-1,k-1)%M);;

        }

	}
	return 0;
}
