#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
         int n;
        cin>>n;
        int zD = 1;
        int zABC = 0;
            for (int i = 1; i <= n; i++) {
            int nzD = zABC * 3LL % mod;
            int nzABC = (zABC * 2LL + zD) % mod;
            zD = nzD;
            zABC = nzABC;
            }
            cout << zD;

        //printf("%d\n",(solve(1,n-1)+solve(2,n-1)+solve(3,n-1))%mod);
        return 0;
    }
