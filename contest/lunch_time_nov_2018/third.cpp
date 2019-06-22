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
const int lim = 1e6;
map<int,vector<int> > M;
int ans[lim];
int main()
{
    int n;
    scan(n);
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        M[n-a].push_back(i);
    }
    int cont = 1;
    for(auto m: M){
        int b = m.first;
        int c = m.second.size();
        if( c%b != 0){
            cout<<"Impossible"<<endl;
            return 0;
        }
        int i = 0;
        for(int a:m.second){
            ans[a] = cont;
            i++;
            if( i == b)
                cont++,i=0;
        }
       
    }
    cout<<"Possible"<<endl;
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }

    return 0;
}
