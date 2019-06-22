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

map<int,int> M;
int main()
{
    int n;
    scan(n);
    string S;
    for(int i=0;i<n;++i){
        cin>>S;
        int m = S.length();
        int cont1 = 0;
        int cont2 = 0;
        int temp = 0;
        int flag = 0;
        for(auto s:S){
            if( s == '('){
                cont1++;
            }
            else{
                if( cont1 > 0){
                    cont1--;
                }
                else{
                    temp--;
                }
            }
        }
        if( cont1 == 0 && temp == 0){
            M[cont1]++;
        }
        else if( cont1 == 0 && temp != 0){
            M[temp]++;
        }
        else if (cont1 > 0 && temp == 0){
            M[cont1]++;
        }
       
    }
    int ans = M[0]/2;
    for(int i=1;i<=500000;++i){
        ans+=min(M[i],M[-i]);
    }
    cout<<ans<<endl;
    return 0;
}
