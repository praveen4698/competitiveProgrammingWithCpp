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
int y,p;
int solve(int hi,int lo)
{
    for(int i=hi;i>=lo;--i)
    {
        int lim = min(p,(int)(sqrt(i))+1);
        int flag = 0;
        for(int j=2;j<=lim;++j)
        {
            if( i%j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    cin>>p>>y;
    int ans = solve(y,max(y-300,p+1));
    cout<<ans<<endl;
    return 0;
}


