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

vector<int> N,Z,P;
vector<int> A;
int main()
{
    int n;
    A.push_back(-1);
    scan(n);
    int maxineg = -1*INF;
    int minipos = INF;
    for(int i=1;i<=n;++i){
        int a;
        scan(a);
        A.push_back(a);
        if( a == 0){
            Z.push_back(i);
            maxineg = max(maxineg,a);
        }
        else if( a < 0){
            N.push_back(i);
        }
        else{
            P.push_back(i);
            minipos = min(minipos,a);
        }
    }
    if( N.size() == n){
        int prev = -1;
        for(int i=0;i<n;++i){
            if( A[i] == maxineg){
                cout<<2<<" "<<A[i]<<endl;
            }
            else{
                cout<<1<<" ";
                if( A[i-1] == )

            }

        }
    }



    return 0;
}
