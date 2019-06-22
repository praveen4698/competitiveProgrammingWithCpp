#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int n;
    cin>>n;
    if( n%10 == 0)
    {
        cout<<n;
        return 0;
    }
    if( n%10 < 5)
    {
        cout<<(n/10)*10;
        return 0;
    }
    cout<<(n/10 + 1)*10;
    return 0;
}
