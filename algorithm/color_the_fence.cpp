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

struct comp
{
    bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
    {
        return (lhs.fi == rhs.fi && lhs.second>rhs.second)||(lhs.fi<rhs.fi);
    }
};
int main()
{
    vector<int> ans,ans1;
    vector<pair<int,int> > A;
    int v;
    scan(v);
    for(int i=1;i<10;++i)
    {
        int a;
        scan(a);
        A.pb({a,i});
    }
    //sort(all(A),comp());
    int temp = v;
    for(int k=0;k<10;++k)
    {

        ans1.clear();
        v = temp;
        random_shuffle(all(A));
        for(int i=0;i<9;++i)
        {
            int n = v/A[i].fi;
            cout<<A[i].se<<endl;
            for(int j=0;j<n;++j)
                ans1.pb(A[i].se);
            v = v%A[i].fi;
        }
        int n = ans1.size();
        int m = ans.size();
        if( n > 0)
        {
            if( (n > m) || (n == m && ans1[0] > ans[0]) )
            {
                ans.clear();
                for(int a:ans1)
                    ans.pb(a);
            }
        }

    }
    if( (int)ans.size() == 0)
        cout<<"-1"<<endl;
    else
        for(auto i:ans)
            cout<<i;

    return 0;
}


