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

vector<int> arr,dep;
int solve()
{
    sort(all(arr));
    sort(all(dep));
    int ans = 0;
    vector<int> Q;
    int j=0;
    for(int i=0;i<dep.size();++i)
    {
        while(dep[i] >= arr[j])
        {
            Q.pb(arr[j]);
            j++;
        }
        ans = max(ans,(int)Q.size());
        Q.pop_back();

    }
    return ans;
}
int main()
{

    int t;
    scan(t);
    while(t--)
    {
        int n;
        cin>>n;
        arr.clear();
        dep.clear();
        arr.resize(n);
        dep.resize(n);

        for(int i=0;i<n;++i)
            cin>>arr[i]>>dep[i];
        cout<<solve()<<endl;
    }
    return 0;
}


