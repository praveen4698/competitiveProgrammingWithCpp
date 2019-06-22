#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;
const ll mod = 998244353;
int main() {
  int n, k;
  cin >> n >> k;
  int g = k;
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    cur %= k;
    g = __gcd(g, cur);
  }
  cout << k / g << "\n";
  for (int i = 0; i < k / g; ++i) {
    cout << i * g << " ";
  }
  cout << "\n";
}