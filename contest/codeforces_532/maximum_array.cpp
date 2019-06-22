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
vector<int> A,B;

map<int,int> M;
int main()
{
    int n,m,k;
    scan3(n,m,k);
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        A.push_back(a);
        B.push_back(a);
    }   
    sort(all(A));
    reverse(all(A));
    ll sum = 0;
    for(int i=0;i<m*k;++i){
        sum = sum + 1ll*A[i];
        M[A[i]]++;
    }
    vector<int> ans;
    int cont = 0;
    for(int i=0;i<n;++i){
        if( M[B[i]] > 0){
            M[B[i]]--;
            cont++;

        }
        if( cont == m){
            cont = 0;
            ans.push_back(i+1);
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<k-1;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
