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
        int frequency[11];
        for(int i=0;i<11;++i)
            frequency[i] = 0;
        int max_count = 0;
        for(int i=0;i<n;++i) {
            int a;
            cin>>a;
            frequency[a]++;
            // max_count = max(max_count, frequency[a]);
        }

        int freq[10001];
        for(int i=0;i<n+1;++i) {
            freq[i] = 0;
        }

        for(int i=1;i<11;++i) {
            if( frequency[i] > 0) {
                freq[frequency[i]]++;
                max_count = max(max_count, freq[frequency[i]]);
            }
            
        }

        // cout<<max_count<<endl;
        for(int i=1;i<=n;++i) {
            if( max_count == freq[i]) {
                cout<<i<<endl;
                break;
            }
        }

    }
    return 0;
}
