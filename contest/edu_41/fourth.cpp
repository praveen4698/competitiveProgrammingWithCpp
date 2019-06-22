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
//#define all(a) (a).begin(),(a).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 1e5+10;
vector<pair<int,int>>  x;

int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        int a,b;
        scan2(a,b);
        x.pb({a,b});
    }
    if( n <= 4)
    {
        printf("YES\n");
        return 0;
    }
    int ans = 0;

    for(int k=0;k<1300;++k)
    {
        random_shuffle(x.begin(),x.end());
        int flag = 0;
        int x1 = x[0].first;
        int x2 = x[1].first;
        int y1 = x[0].second;
        int y2 = x[1].second;
        int x3 = x[n-1].first;
        int x4 = x[n-2].first;
        int y3 = x[n-1].second;
        int y4 = x[n-2].second;
        int cont1=0 ,cont2=0;
        for(int i=2;i<n-2;++i)
        {
            int tx = x[i].first;
            int ty = x[i].second;
            if( x1 == x2 && x2 == tx)
            {
                cont1++;
            }
            else if( y1 == y2 && y2 == ty)
            {
                cont1++;
            }
            else if( (x2 != x1) && (y2 != y1) && ((x2-x1)*1ll*(ty-y1) == (tx-x1)*1ll*(y2-y1)))
            {
                cont1++;
            }
            else if( x3 == x4 && x3 == tx)
                cont2++;
            else if( y3 == y4 && y4 == ty)
                cont2++;
            else if( (x4 != x3) && (y3 != y4) &&((x4-x3)*1ll*(ty-y3) == (tx-x3)*1ll*(y4-y3)))
                cont2++;
            else
            {
                flag = 1;
                break;
            }

        }
        if( flag == 0)
        {
            ans = 1;
            break;
        }


    }
    if( ans == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}


