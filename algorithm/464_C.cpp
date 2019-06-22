#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

const int lim = 1e5+10;
int A[lim];
int main()
{
    int n;
    scan(n);
    for(int i=1;i<=n;++i)
    {
        scan(A[i]);
    }
    int s,f;
    scan2(s,f);
    f--;
    int cont = 1;
    int ans = 1;
    int sum = 0;
    for(int i=s;i<=f;++i)
        sum+=A[i];
    int maxi = sum;
    int j = f;
    if(  j == 0)
        j = n;
    int i = s-1;
    if( i == 0)
        i = n;
    for(int k = 0;k<n;++k)
    {
        cont++;
        sum += A[i];
        i--;
        if( i == 0)
            i = n;
        sum-=A[j];
        j--;
        if( j == 0)
            j = n;
        if( sum > maxi)
        {
            ans = cont;
            maxi = sum;

        }
    }
    cout<<ans<<endl;
    return 0;
}


