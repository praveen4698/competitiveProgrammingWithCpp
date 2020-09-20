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
        vector<int> A;
        cin>>n;
        for(int i=0;i<n;++i ){
            int a;
            cin>>a;
            A.push_back(a);
        }
        reverse(A.begin(), A.end());
        for(int i=0;i<n;++i) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
