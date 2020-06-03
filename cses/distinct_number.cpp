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

int main() {
    fast int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i<n;++i) {
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<endl;
    return 0;
}
