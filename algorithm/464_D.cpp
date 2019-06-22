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
int par[101];

int parent(int x)
{
    if(par[x] == x)
        return x;
    else
        return parent(par[x]);
}
int main()
{
    fast
    int n;
    cin>>n;

    string A,B;
    cin>>A>>B;
    vector<pair<char,char> > ans;
    for(int i=0;i<100;++i)
        par[i] = i;
    for(int i=0;i<n;++i)
    {
        char a = (char)A[i];
        char b = (char)B[i];
        int fa = parent(a-'a');
        int fb = parent(b-'a');
        if( fa == fb)
            continue;
        par[fb] = fa;
        char x = (char)('a' + fa);
        char y = (char)('a' + fb);
        ans.pb({x,y});
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i].first<<" "<<ans[i].second ;
        if( i != ans.size()-1)
            cout<<endl;

    }
    return 0;
}


