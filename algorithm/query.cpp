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

const int lim =  1e5+10;
int Dp[10][lim],A[lim];
int main()
{
    memset(Dp,0,sizeof(int));
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        if( i >=  1)
        {
            for(int j=0;j<10;++j)
            {
                Dp[j][i]+=Dp[j][i-1];
            }
        }
        Dp[A[i]][i]+=1;
    }

    int q;
    scan(q);
    while(q--){
        int a,b,c;
        scan3(a,b,c);
        int ans = Dp[c][b];


     //   cout<<"cvzx"<<Dp[c][b]<<endl;


       if( a > 0)
            ans-=Dp[c][a-1];
    //    cout<<ans<<endl;
//

        if( ans > 0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}


