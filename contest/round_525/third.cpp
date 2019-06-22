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

set<int> A;
int main()
{
    int n,k;
    scan2(n,k);
    
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        A.insert(a);
    }
    // sort(all(A));
    n = A.size();
    int prev = 0;
    auto itr = A.begin();
    for(int i=0;i<min(n,k);++i){
        cout<<(*itr)-prev<<endl;
        prev = (*itr);
        itr++;
    }
    if( k > n){
        for(int i=n;i<k;++i){
            cout<<"0"<<endl;
        }
    }
    return 0;
}
