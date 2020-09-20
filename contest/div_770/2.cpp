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
        int n;
        cin>>n;
        vector<long long int> negative;
        vector<long long int> positive;
        vector<long long int> all;

        for(int i=0;i<n;++i) {
            long long int a;
            cin>>a;
            all.push_back(a);
            if( a < 0) {
                negative.push_back(a);
            }
            else {
                positive.push_back(a);
            }
        }

        sort(all.begin(), all.end());
        reverse(all.begin(),all.end());
        long long int ans = all[0]*all[1]*all[2]*all[3]*all[4];

        sort(negative.begin(), negative.end());

        sort(positive.begin(), positive.end());
        reverse(positive.begin(), positive.end());

        if( positive.size() >= 5) {
            ans = max(ans, positive[0]*positive[1]*positive[2]*positive[3]*positive[4]);
        }   
        
        if( positive.size() >= 3 and negative.size() >= 2) {
            ans = max(ans, positive[0]*positive[2]*positive[1]*negative[1]*negative[0]);
        }
        
        if( positive.size() >= 1 and negative.size() >= 4) {
            ans = max(ans, positive[0]*negative[0]*negative[1]*negative[2]*negative[3]);
        }

        cout<<ans<<endl;
        
    }
    return 0;
}
