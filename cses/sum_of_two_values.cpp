#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define scan(a) scanf("%d", &a)
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define print(x) printf("%d\n", x)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;

int main()
{
    fast int n;
    vector<int> A;
    map<int, vector<int>> M;
    cin >> n;
    int sum;
    cin >> sum;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        A.push_back(a);
        M[a].push_back(i + 1);
    }
    sort(all(A));
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (A[l] + A[r] == sum)
        {
    
            if (A[l] == A[r])
            {
                cout << M[A[l]][0] << " " << M[A[l]][1] << endl;
            }
            else
            {
                cout << M[A[l]][0] << " " << M[A[r]][0] << endl;
            }

            return 0;
        }
        else if (A[l] + A[r] > sum)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
