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
    double A[1001];
    while(t--)
    {
        int n;
        double e;
        cin>>n>>e;
        for(int i=0;i<n;++i)
            cin>>A[i];
        if( n == 1)
        {
            if( A[0] == e)
                cout<<"1"<<endl;
            else
                cout<<"-1"<<endl;
            continue;
        }
        double temp = (e-A[1])/A[0];
        double ans = 1/(temp+1);
        if(ans >= 0.00 && ans <= 1.00)
        {
            cout<<1-ans<<" ";
            cout<<ans<<" ";
            for(int i=0;i<n-2;++i)
                cout<<"0 ";
        }
        else
            cout<<"-1";
        cout<<endl;




    }
    return 0;
}


