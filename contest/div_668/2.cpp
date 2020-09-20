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
        vector<long long int> A;
        for(int i=0;i<n;++i) {
            int a;
            cin>>a;
            A.push_back(a);
        }

        int i=0,j=0;
        while(j < n and i<n) {
            if( A[i] < 0) {
                if( i == j) {
                    j++;
                }
                i++;
            }
            else {
                if( A[j] < 0) {
                    long long int value = abs(A[j]);
                    if( value == A[i]) {
                        A[j] = 0;
                        A[i] = 0;
                        i++;
                        j++;
                    }
                    else if( value < A[i]) {
                        A[i] = A[i] - value;
                        A[j] = 0;
                        j++;
                    }
                    else {
                        A[j] = A[j] + A[i];
                        A[i] = 0;
                        i++;
                    }
                }
                else {
                    j++;
                }
            }
        }
        long long int ans = 0;
        for(int i=0;i<n;++i) {
            if( A[i] > 0ll) {
                ans += A[i];
            }
        }
        cout<<ans<<endl;

    }
    
    return 0;
}
