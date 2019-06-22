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


int main()
{
    int n;
    scan(n);
    int A[101];
    int maxi = 0;
    int sum = 0;
    for(int i=0;i<n;++i){
        scan(A[i]);
        sum+=A[i];
        maxi = max(maxi,A[i]);

    }
    for(int k=1;k<=250;++k){
        int cont = 0;
        // cout<<sum<<endl;
        for(int i=0;i<n;++i){
            if( A[i] > k){
                cont = -1;
                break;
            }
            cont+=k-A[i];
        }

        if( cont > sum){
            cout<<k<<endl;
            return 0;
        }
    }
    return 0;
}
