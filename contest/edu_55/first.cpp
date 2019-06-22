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
const int lim = 1e5+10;
int cont[lim];
vector<int> G,S;
int main()
{
    int n;
    string s;
    int sum = 0;
    scan(n);
    cin>>s;
    memset(cont,0,sizeof(cont));
    for(int i=0;i<n;++i){
        if( s[i] == 'S')
        {   cont[i+1] = 0;
            S.push_back(i+1);
        }
        else
            cont[i+1] = cont[i]+1,sum++;
    }
    int ans = -1;
    cont[n+1] = 0;
    for(int i=1;i<=n;++i){
        ans = max(ans,cont[i]);
    }
    if( S.size() == 0){
        cout<<n<<endl;
        return 0;
    }
    if( S.size() == 1 ){
        cout<<n-1<<endl;
        return 0;
    }
    for(int i=0;i<S.size()-1;++i){
        int temp = 0;
        if( S[i] + 1 == S[i+1]){
             int t = cont[S[i+1] + 1] + cont[S[i] -1] ;
             if( sum >= t+2){
                 ans = max(ans,t+2);
             }
             else if( sum == t+1){
                ans = max(ans,t+1);
             }
             else{
                 ans = max(ans,t);
             }

        }
        else {
            int t = cont[S[i+1] + 1] + cont[S[i] -1] + cont[S[i] + 1]  ;
             if( sum >= t+2){
                 ans = max(ans,t+2);
             }
             else if( sum == t+1){
                
                ans = max(ans,t+1);
             }
             else{
                 ans = max(ans,t);
             }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
