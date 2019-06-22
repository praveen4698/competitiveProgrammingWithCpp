#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n;
        S(n);
        int one = 0,two = 0,three = 0;
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            int a;
            S(a);
            if(a%4 == 1)
                one++;
            if( a%4 == 2)
                two++;
            if( a%4 == 3)
                three++;
        }
       // cout<<one<<two<<three<<endl;
        ans+=min(one,three);
        int mini = min(one,three);
        one-=mini;
        three-=mini;
        if( one == 0)
            swap(one,three);
        //cout<<one<<endl;
        ans+=(2*min(one/2,two));
        mini = min(one/2,two);
        one-=(2*mini);
        two-=(mini);
        ans+=(3*(one/4));
        one-=4*(one/4);
        ans+=((two/2));
        two-=(2*(two/2));
        if( one == 0 && two == 0 && three == 0)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;


    }
    return 0;
}
