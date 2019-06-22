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
int ans[lim];
int main()
{
    string S;
    cin>>S;
    int n = S.size();
    memset(ans,0,sizeof(lim));
    for(int i=1;i<n-1;++i){
        if( S[i] == 'a'){
            if( S[i+1] == 'b' )
                ans[i] = 1;
        }
        if(S[i] == 'b'){
            if( S[i+1] == 'a')
                ans[i] = 1;
        }
    }
    if( S[n-1] == 'a')
        ans[n-1] = 1;

    for(int i=0;i<n;++i){
        printf("%d ",ans[i]);
    }
    return 0;
}
