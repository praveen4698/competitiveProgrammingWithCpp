#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;

vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}


int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int> > A;
        for(int i=0;i<n;++i) {
            vector<int> x;
            A.push_back(x);
        }

        vector<int> edge;
        for(int i=0;i<n-1;++i) {
            int a, b;
            cin>>a>>b;
            A[a-1].push_back(b-1);
            A[b-1].push_back(a-1);
            edge.push_back(a);
            edge.push_back(b);
        }   

        vector<int> centroid = Centroid(A);

        if( centroid.size() == 1) {
            cout<<edge[0]<<" "<<edge[1]<<endl;
            cout<<edge[0]<<" "<<edge[1]<<endl;
        }
        else {
            int centroid_1 = centroid[0];
            int centroid_2 = centroid[1];
            int ans_1 =-1;
            if( A[centroid_1][0] == centroid_2 ) {
                ans_1 = A[centroid_1][1];
            }
            else {
                ans_1 = A[centroid_1][0];
            }

            cout<<centroid_1+1<<" "<<ans_1+1<<endl;
            cout<<centroid_2+1<<" "<<ans_1+1<<endl;

        }
    }
    return 0;
}
