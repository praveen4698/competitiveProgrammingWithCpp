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

vector<int> A,ans,temp;
int main()
{

    int n;
    scan(n);
    A.resize(n);
    for(int i=0;i<n;++i)
        cin>>A[i],ans.pb(i);
    int q;
    scan(q);
    while(q--)
    {
        int a;
        cin>>a;
        for(int i=0;i<ans.size();++i)
        {
            A[ans[i]]/=a;
            if( A[ans[i]] > 0)
                temp.pb(ans[i]);
        }
        ans.clear();
        for(int i:temp)
            ans.pb(i);
        temp.clear();
    }
    for(int i:A)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}


