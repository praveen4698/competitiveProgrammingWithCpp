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

vector<int> A,B,C,D;
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i){
        string S;
        int a ;
        cin>>S>>a;
        if( S[0] == '0' && S[1] == '0')
            A.push_back(a);
        if( S[0] == '0' && S[1] == '1')
            B.push_back(a);
        if( S[0] == '1' && S[1] == '0')
            C.push_back(a);
        if( S[0] == '1' && S[1] == '1')
            D.push_back(a);
    }
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    sort(all(C));
    reverse(all(C));
    sort(all(D));
    reverse(all(D));
    int ans = 0;
    int i=0;
    int l = min( min(A.size(),B.size()),min(C.size(),D.size()));
    while(i<l){
        ans+=(A[i]+B[i]+C[i]+D[i]);
    }
    int l = min( B.size(),min(C.size(),D.size()));
    while(i<l){
        ans+=(B[i]+C[i]+D[i]);
    }
    int l = min(B.size(),C.size());
    while(i<l){
        ans+=()
    }
    cout<<ans<<endl;
    return 0;
}
