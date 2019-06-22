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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int phi(int n)
{   int ret=n; int i = 2;
    if(n%i==0)
    {
        ret-=ret/i;
        while(n%i==0)
            n/=i;
    }
    for(i=3; i*i<=n; i++)
        if(n%i==0)
        {
            ret-=ret/i;
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        ret-=ret/n;
    return ret;
}
int main()
{
    int t;
    scan(t);
    int  x = 1;
    while(t--)
    {
        int a,b;
        scan2(a,b);
        printf("Case %d: ",x);
        x++;
		if(phi(b)<phi(a))
        {
				printf("Shibli took it\n");
		}
		else
        {
			printf("Swapnil lost it\n");
		}
    }
    return 0;
}


