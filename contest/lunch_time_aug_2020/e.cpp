#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const int mod = 1e9 + 7;
const int lim = 1e6;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a,int b){
	int x = 1%mod;
	while(b){
		if(b&1) x = mul(x, a);
		a = mul(a,a);
		b >>= 1;
	}
	return x;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<int> A(n-1, 0);
        for(int i=0;i<n-1;++i) {
            int a;
            cin>>a;
            A[i] = a;
        }
        sort(A.begin(), A.end());
        int flag = 1;
        int ans = 1;
        int prev = A[0];
        int count = 1;
        vector<int> B;
        // for(int i=0;i<n-1;++i) {

        // }
        for(int i=1;i<n-1; ++i) {
            if( A[i] == A[i-1] ) {
                count++;
            }
            else if( A[i] == A[i-1] + 1) {
                B.push_back(count);
                count = 1;
                prev = A[i];
            }
            else {
                flag = -1;
            }
        }

        B.push_back(count);
        if(A[0] > 1 ||  flag == -1) {
            cout<<"0"<<endl;
        }
        else {
            
            if( B.size() >= 2 ) {
                // for(int i=0;i<int(B.size()); ++i) {
                //     cout<<B[i]<<">>>>>>>>>>"<<endl;
                // }
                for(int i=1;i< int(B.size()); ++i) {
                    ans = mul(ans,pow(B[i-1], B[i]));
                    // ans %= mod;
                }
            }
            cout<<ans<<endl;
        }


    }
    return 0;
}
