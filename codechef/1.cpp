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
        int n, k;
        cin>>n>>k;
        vector<int> A(n, 0);
        int flag = 0;
        for(int i=0;i<n;++i) {
            cin>>A[i];
            if( A[i] > k) {
                flag = -1;
            }
        }
 
        if( flag == -1) {
            cout<<"-1"<<endl;
        }
        else {
            int count = 1;
            int prev = 0;
            for(int i=0;i<n;++i) {
                if( prev + A[i] > k) {
                    count++;
                    prev = A[i];
                }
                else {
                    prev += A[i];
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
