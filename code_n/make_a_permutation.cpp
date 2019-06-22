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

const int lim = 1e5+10;
int A[lim];
int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        for(int i=0;i<n+1;++i){
            A[i] = 0;
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            int a;
            scan(a);
            if( a > n)
                ans++;
            else if(A[a] == 1)
                ans++;
            else
                A[a] = 1;

        }
        print(ans);
    }
    return 0;
}