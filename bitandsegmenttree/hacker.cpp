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
const int lim = 1e5+10;
multiset<int> S;
vector<int> A(lim),B(lim),cost[lim];
ll sum = 0;
int main()
{
    int n;
    S(n);
    for(int i=0;i<n;++i)
        S(A[i]);
    for(int i=0;i<n;++i)
    {
        S(B[i]);
        S.insert(B[i]);
        sum+=1ll*B[i];
    }
    for(int i=0;i<n;++i)
    {
        cost[A[i]].push_back(B[i]);
    }
    ll ans = INFL;
    for(int i=100001;i>=1;--i)
    {
        if( cost[i].size() > 0)
        {
            ll t = 0ll;
         //   cout<<i<<" "<<sum<<endl;
            for(auto a:cost[i])
            {
                t+=1ll*a;
                S.erase(S.find(a));
            }
            int cont = cost[i].size()-1;
          //  cout<<"t = "<<t<<endl;
            for(auto it = S.rbegin();it != S.rend();++it)
            {
                t+=1ll*(*it);
                //cout<<*it<<endl;
                cont--;
                if( cont == 0)
                    break;
            }
           // cout<<"t = "<<t<<endl;
            ans = min(ans,sum-t);

        }
    }
    cout<<ans<<endl;
    return 0;
}
