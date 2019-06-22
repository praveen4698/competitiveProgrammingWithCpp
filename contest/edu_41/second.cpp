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
int A[lim],t[lim];

int main()
{
    int n,k;
    scan2(n,k);
    for(int i=0;i<n;++i)
        scan(A[i]);
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        scan(t[i]);
        if(t[i] == 1)
            ans+=A[i];
    }
    int temp = 0;
    for(int i=0;i<k;++i)
    {
        if(t[i] == 0)
            temp+=A[i];
    }
    int ret = 0;
    ret = ans + temp;
    for(int i=k;i<n;++i)
    {
        if( t[i-k] == 0)
            temp = temp - A[i-k];
        if( t[i] == 0)
            temp += A[i];
        ret = max( temp+ans,ret);
    }

        cout<<ret<<endl;

    return 0;
}


