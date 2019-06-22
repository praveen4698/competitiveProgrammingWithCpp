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

const int lim = 1001;
int A[lim];
int diff[lim];
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i){
        scan(A[i]);
    }
    diff[0] = A[0];
    for(int i=1;i<n;++i){
        diff[i] = A[i] - A[i-1];
    }
    set<int> ans;
    for(int k=1;k<=n;++k ){
        bool flag = true;
        for(int i=0;i<n;++i){

            if( diff[i] != diff[i%k]){
                flag = false;
            }
        }
        if( flag == true){
            ans.insert(k);
        }
    }
    cout<<ans.size()<<endl;
    for(int a:ans){
        printf("%d ",a);
    }
    return 0;
}
