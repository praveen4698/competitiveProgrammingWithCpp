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
int e,m,h;
bool f(int x)
{
    int sum = min(e-x,(x+1)/2)+min(m-x,(x+1)/2)+min(h,(x+1)/2);
    return sum >= x;
}

int main()
{
    int t;
    scan(t);
    while(t--)
    {
        scan3(e,m,h);
        int l = 0;
        for(int i=0;i<m+1;++i)
        {
            if( f(i))
                l = max(l,i);
        }
        cout<<l<<endl;
    }
    return 0;
}


