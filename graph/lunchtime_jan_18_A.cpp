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


int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        int odd = 0;
        for(int i=0;i<n;++i)
        {
            int a;
            scan(a);
            if( a%2 == 1)
                odd++;
        }
        if( odd%2 == 1 || n == 1)
            cout<<"2"<<endl;
        else
            cout<<"1"<<endl;
    }
    return 0;
}


