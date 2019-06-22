#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int n;
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    if( a > b)
    {
        int i = 0;
        while(i<=n)
        {
            if( (n-i)%b == 0)
            {
                cout<<"YES"<<endl;
                cout<<i/a<<" "<<(n-i)/b<<endl;
                return 0;
            }
            i+=a;
        }
    }
    else
    {
        int i = 0;
        while(i<=n)
        {
            if((n-i)%a == 0)
            {
                cout<<"YES"<<endl;
                cout<<(n-i)/a<<" "<<i/b<<endl;
                return 0;
            }
            i+=b;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
