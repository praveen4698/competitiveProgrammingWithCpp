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
int des;
void solve(vector<pair<int,int> > &ans,int i,int j)
{
    if( i == j && i == des)
    {
        ans.push_back({i,j});
        for(auto a:ans)
            cout<<a.first<<" "<<a.second<<endl;
        cout<<ans.size()<<endl;

        return ;
    }
    if( i == j)
        return ;
    int mid = (i+j)/2;
    ans.push_back({i,j});
    solve(ans,i,mid);
    solve(ans,mid+1,j);
    ans.pop_back();
    return ;
}
int main()
{
    int t;
    S(t);
    ll mod = 1e9+7;
    while(t--)
    {
       vector<pair<int,int> > ans;
       int a,b;
       cin>>a>>b>>des;
       if( des < a || des > b)
       {
           cout<<"-1"<<endl;
           continue;
       }
       solve(ans,a,b);
    }
    return 0;
}
