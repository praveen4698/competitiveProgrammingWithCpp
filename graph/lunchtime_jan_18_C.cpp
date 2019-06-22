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
vector<int> ans;
int A[100000];
int main()
{
    int n,k;
    scan2(n,k);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
    }
    for(int i=0;i<n;++i)
    {
        int mini = A[i];
        int xori = A[i];
        ans.push_back(mini*xori);
        for(int j= i+1;j<n;++j)
        {
            mini = min(A[j],mini);
            xori = xori^A[j];
            ans.push_back(mini*xori);
        }
    }
    sort(all(ans));
    cout<<ans[k-1]<<endl;
    return 0;
}

