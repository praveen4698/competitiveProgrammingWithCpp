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
int dp[1001][101];
int cost[1001][101];
int Range = 255;
int main(){

    string A = "tower";
    char ans[10];
    int count[Range+1];
    cout<<"as"<<endl;
    memset(count,0,sizeof(count));
    for(int i=0;A[i];++i){
        ++count[A[i]];
    }
    count[0] = 0;
    cout<<"as"<<endl;
    for(int i=1;i <= Range ; ++i){
        count[i]+=count[i-1];
    }
    cout<<"as"<<endl;
    for(int i=0;i<5;++i){
        cout<<count[A[i]]<<endl;
        ans[count[A[i]]] = A[i];
        cout<<i<<endl;
        count[A[i]]--;
        cout<<count[A[i]]<<endl;
    }
    cout<<"ad"<<endl;
    for(char a:ans)
        cout<<a<<endl;
    return 0;
}

