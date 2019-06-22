#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e+10;
vector<int> A;

int main()
{
    int t;
    scan(t);
    while(t--){

        int n;
        scan(n);
        A.clear();
        A.resize(n);
        for(int i=0;i<n;++i){
            scan(A[i]);
        }
        sort(all(A));
        int ans = INF;
        for(int i=1;i<n;++i){
            ans = min(ans,A[i]-A[i-1]);
        }
        printf("%d\n",ans);


    }

    return 0;
}


