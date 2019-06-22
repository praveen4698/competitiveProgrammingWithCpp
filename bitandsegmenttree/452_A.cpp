#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int n;
    int two=0,one = 0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int a;
        scanf("%d",&a);
        if( a == 2)
            two++;
        else
            one++;
    }
    if( two > one)
    {
        cout<<one<<endl;
        return  0;
    }
    int diff = one -two;
    cout<<diff/3 + two<<endl;
    return 0;
}
