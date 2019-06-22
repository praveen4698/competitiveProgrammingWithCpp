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
map<char,int> M;
string s;
int main()
{
    int t;
    scan(t);
    while(t--){
        M.clear();
        cin>>s;
        for(char a:s)
            M[a]++;
        if( M.size() == 1){
            cout<<"-1"<<endl;
        }
        else{
            for(auto m:M){
                for(int i=0;i<m.second;++i)
                    cout<<m.first;

            }
            cout<<endl;
        }
        
    }
    return 0;
}
