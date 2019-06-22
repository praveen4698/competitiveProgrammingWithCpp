#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

string A[501];
int n;
int solve()
{
    int ans1 = 0;
    int ans2 = 0;
    for(int i=0;i<2*n;++i)
    {
        for(int j=0;j<2*n;++j)
        {
            if( (i+j)%2 == 0 && A[i][j] == '1')
                ans1++;
            if( (i+j)%2 == 1 && A[i][j] == '0')
                ans1++;
            if( (i+j)%2 == 0 && A[i][j] == '0')
                ans2++;
            if( (i+j)%2 == 1 && A[i][j] == '1')
                ans2++;
        }
    }
    return min(ans1,ans2);
}
int main()
{

    string one[5][101],two[101],three[101],four[101];
    scan(n);
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<n;++j)
            cin>>one[i][j];
        if(i<3)
        cout<<endl;
    }
    vector<int> b;
    b.pb(0);
    b.pb(1);
    b.pb(2);
    b.pb(3);
    int ans = INF;
    for(int k=0;k<30;++k)
    {
        next_permutation(all(b));
        for(int i=0;i<2*n+10;++i)
            A[i].clear();
        for(int i=0;i<n;++i)
            A[i]+=one[b[0]][i];
        for(int i=0;i<n;++i)
            A[i]+=one[b[1]][i];
        for(int i=0;i<n;++i)
            A[i+n]+=one[b[2]][i];
        for(int i=0;i<n;++i)
            A[i+n]+=one[b[3]][i];
        ans = min(ans,solve());

    }
    cout<<ans<<endl;
    return 0;
}


