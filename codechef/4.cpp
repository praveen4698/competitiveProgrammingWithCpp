#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;
const int limit = 1000005;
int color_array[limit];
vector<int> G[limit];
string clr;
long long int count_1;

int DFS(int child, int parent, int color) {

    vector<int> A;
    for(int i: G[child]) {
        if( i == parent)
            continue;

        int a = DFS(i, child, (1+color)%2);
        if( a > 0) {
            A.push_back(a);
        }
    } 
    if( color_array[child] != color) {
        A.push_back(0);
    }
    int ret = 0;
    int n = A.size();
    if(n%2 == 1) {
        ret = A[n -1];
        n--;
    }
    for(int i=0;i<n;++i) {
        count_1 += 1ll*A[i];
    }
    if( A.size()%2 == 0)
        return 0;
    return ret+1;

}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=0;i<n+1;++i)
            G[i].clear();
        for(int i=0;i<n-1;++i) {
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        } 
        cin>>clr;
        for(int i=0;i<n;++i) {

            color_array[i+1] = clr[i] == '1' ? 1 : 0;
        }
        count_1 = 0ll;
        long long int ans = -1ll;
        int tt = DFS(1, -1, 0);
        if( tt == 0) {
            ans = count_1;
        }
        count_1 = 0;
        tt  = DFS(1, -1, 1);
        if( tt == 0){
            if( ans == -1ll) {
                ans = count_1;
            }
            else {
                ans = min(ans, count_1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
