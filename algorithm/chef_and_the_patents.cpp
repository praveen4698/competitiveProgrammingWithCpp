#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
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
        int n,m,x,k;
        string s;
        scan2(n,m);
        scan2(x,k);
        cin>>s;
        int even = 0,odd = 0;
        for(auto a:s)
        {
            if( a == 'E')
                even++;
            else
                odd++;
        }
        int cont = 0;
        for(int i=1;i<=m;++i)
        {
            if( i%2 == 0)
            {
                if( x >= even)
                {
                    cont+=even;
                    even = 0;
                }
                else
                {
                    cont+=x;
                    even-=x;
                }
            }
            else
            {
                if( x >= odd)
                {
                    cont+=odd;
                    odd = 0;
                }
                else
                {
                    cont+=x;
                    odd-=x;
                }
            }
        }
        if(cont < n)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}


