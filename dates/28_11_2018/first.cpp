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

map<string,int> cont;
map<string,string> value;
map<string,int> M;
int main()
{
    int n;
    scan(n);
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        int t = s.size() ;
        M.clear();
        for(int j=0;j<t;++j){
            string temp = "";
            // M.clear();
            for(int k=j;k<t;++k){
                temp+=s[k];
                if( M[temp] >= 1)
                    continue;
                M[temp]++;
                cont[temp]+=1;
                value[temp] = s;

            }
        }
    }
    int q;
    scan(q);
    while(q--){
        string a;
        cin>>a;
        if( cont[a] >= 1){
            cout<<cont[a]<<" "<<value[a]<<endl;
        }
        else{
            cout<<"0 -"<<endl;
        }
    }
    return 0;
}
