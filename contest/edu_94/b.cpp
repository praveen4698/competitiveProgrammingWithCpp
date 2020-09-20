#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


int main()
{
    int t;
    cin>>t;
    while(t--) {
        int capacity_a, capacity_b;
        cin>>capacity_a>>capacity_b;
        int count_sword, count_axe;
        cin>>count_sword>>count_axe;

        int weight_sword, weight_axe;
        cin>>weight_sword>>weight_axe;

        int ans = 0;
        int n = min(count_sword, capacity_a/weight_sword);
        for(int i=0;i<=n;++i) {
            int temp_a = capacity_a - i*weight_sword;
            int a_axe = min(count_axe, temp_a/weight_axe);

            int t_count_sword = count_sword - i;
            int t_count_axe = count_axe - a_axe;

            int b_axe = 0;
            int b_sword = 0;
            if( weight_axe < weight_sword) {
                b_axe = min( t_count_axe, capacity_b/weight_axe);
                int temp_b = capacity_b - b_axe*weight_axe;
                b_sword = min(t_count_sword, temp_b/weight_sword);
            }
            else {
                b_sword = min(t_count_sword, capacity_b/weight_sword);
                int temp_b = capacity_b - b_sword*weight_sword;
                b_axe = min(t_count_axe, temp_b/weight_axe);
            }

            ans = max(ans, i+a_axe+b_axe+b_sword);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
