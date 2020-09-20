#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


bool check(vector<double> &A, double d, double cooldown) {

    double prev = 1.00*A[0] + cooldown;
    int n = A.size();
    for(int i=1;i<n;++i) {
        if( A[i] + d >= prev)
        {
            if( A[i] >= prev) {
                prev = A[i] + cooldown;
            }
            else {
                prev = prev + cooldown;
            }
        
        }
        else {
            return false;
        }
    }
    return true;
}

int main()
{
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        double d;
        cin>>n>>d;
        vector<double> A(n,0.0);
        for(int i=0;i<n;++i)
            cin>>A[i];

        sort(A.begin(),A.end());

        double lo = double(0.0);
        double hi = double(100000000000.00);
        double ans = 0.0;
        int count = 0;
        while( hi-lo > 0.0000001) {
            double mid = lo + (hi-lo)/2.00;
            // printf("%.5f\n", mid);
            // cout<<lo<<" "<<hi<<" "<<mid<<endl;
            // cout<<ans<<" >>>>>>>>>"<<endl;
            if( check(A,d , mid)) {
                ans = mid;
                lo = mid + 0.0000001;
            }
            else {
                hi = mid - 0.0000001;
            }

            // break;
            count++;
            if(count > 50)
                break;
        }
        cout << std::setprecision(7) << ans << endl;
        // cout<<ans<<endl;
    }
    return 0;
}
