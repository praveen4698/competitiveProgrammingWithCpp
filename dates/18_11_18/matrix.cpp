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

vector<int> r,c;
string s;
vector<vector<int> > A;
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,m;
        scan2(n,m);
        r.clear();
        c.clear();
        r.resize(n,0);
        c.resize(m,0);
        A.clear();
        A.resize(n);
        int flag = 1;
        for(int i=0;i<n;++i){
            cin>>s;
            for(int j=0;j<m;++j){
                int a = (int)s[j] - '0';
                A[i].push_back(a);
                if( a== 1){
                    flag = 0;
                    r[i] = c[j] = 1;
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( flag == 1){
                    cout<<"-1 ";
                }
                else if( A[i][j] == 1 || flag == 1 ){
                    cout<<"0 ";
                }
                else if(  r[i] == 1 || c[j] == 1){
                    cout<<"1 ";
                }
                else{
                    cout<<"2 ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
