#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;

int rangeBitwiseAnd(int m, int n) {
        
        int flag = 0;
        long long ans = 0;
        int bit = 30;
        int i = 1;
        while(1) {
            long long int  value = 1<<bit;
            cout<<value<<endl;
            if(value <= 1ll*m) {
                m = 1ll*m - value;
                n = 1ll*n -value;
                ans = value;
                flag = 1;
            }
            if( flag == 1 and value > m)
                break;
            bit--;
            if( bit < 0)
                break;
        }
        return ans;
        
    }
int main() {
    
    // cout<<rangeBitwiseAnd(1,2)<<endl;
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.erase(1);
    for(int i : s) {
        cout<<i<<endl;
    }
}