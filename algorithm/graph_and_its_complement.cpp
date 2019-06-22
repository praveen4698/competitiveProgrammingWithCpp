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
const int lim = 1e3+10;
int ans[lim][lim];
vector<int> G[lim];

int main()
{
    int n,a,b;
    scan3(n,a,b);
    if( n == 1)
    {
        if( a == 1 && b== 1)
        {
            cout<<"YES"<<endl;
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return 0;
    }
    if( (n == 2 || n == 3) && a == 1 && b == 1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if( a > 1 && b > 1)
    {
        printf("NO");
        return 0;
    }
    if( b == 1)
    {

    //printf("fasdf\n");
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n-a;++i)
        {
            ans[i+1][i] = 1;
            ans[i][i+1] = 1;
        }
   // for(int i=0;i<n;++i)

        printf("YES\n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cout<<ans[i][j];
            cout<<"\n";
        }
        return 0;
    }
    if(   a == 1)
    {


        memset(ans,0,sizeof(ans));
        for(int i=0;i<n-b;++i)
        {
            ans[i+1][i] = 1;
            ans[i][i+1] = 1;
        }
        printf("YES\n");
        for(int i=0;i<n;++i)
        {
            ans[i][i] = 1;
            for(int j=0;j<n;++j)
                cout<<(1-ans[i][j]);
            cout<<"\n";
        }
    }


    return 0;
}


