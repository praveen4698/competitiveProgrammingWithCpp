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
const int lim = 1e6+10;
int bit[lim+1];
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
int main()
{
    int n;
    scan(n);
    for(int i=1;i<=n;++i)
    {
        int a;
        scan(a);
        update(i,a);
        update(i+1,-a);
    }
    int q;
    scan(q);
    while(q--)
    {
        int a;
        scan(a);
        if( a == 1)
        {
            int x;
            cin>>x;
            update(1,-1);
            update(x+1,+1);
        }
        else
        {
            int l = 1;
            int r = n;
            int ans = -1;
            int x;
            cin>>x;
            while(l<=r)
            {

                int mid = (l+r)/2;
                if( query(mid) > x)
                    r = mid-1;
                else if( query(mid) < x)
                     l = mid+1;
                else
                {
                    ans = mid;
                    break;
                }

            }
            if( query(ans) == x)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
    return 0;
}


