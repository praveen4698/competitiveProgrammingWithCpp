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

const int lim = 25;
int ans[lim][lim];
int cont[1001];
int main()
{
    memset(cont,0,sizeof(cont));
    memset(ans,-1,sizeof(ans));
    int n;
    scan(n);
    for(int i=0;i<n*n;++i){
        int a;
        scan(a);
        cont[a]++;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){

            if( n&1 && (i == (n+1)/2 || j==(n+1)/2))
                continue;

            if( ans[i][j] == -1){
                int temp = -1;
                for(int k=1;k<=1000;++k){
                    if( cont[k] >= 4){
                        temp = k;
                        cont[k]-=4;
                        break;
                    }
                }
                // cout<<temp<<" "<<i<<" "<<j<<endl;
                ans[i][j] = temp;
                ans[i][n-j+1] = temp;
                ans[n-i+1][j] = temp;
                ans[n-i+1][n-j+1] = temp; 
                // for(int a=1;a<=n;++a){
                //     for(int b=1;b<=n;++b){
                //             cout<<ans[a][b]<<" ";
                //      }
                //     cout<<endl;
                // }

                // cout<<endl<<endl;
            }

        }
    }

    if( n&1){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if( (n+1)/2 == i && (n+1)/2 = j){
                    continue;
                if((n+1)/2 != i && )
                if( ans[i][j] == -1){
                    int temp = -1;
                    for(int k=1;k<=1000;++k){
                        if( cont[k] >= 2){
                            temp = k;
                            cont[k]-=2;
                            break;
                        }
                    }
                    // cout<<temp<<" "<<i<<" "<<j<<endl;
                    ans[i][j] = temp;
                   // ans[i][n-j+1] = temp;
                   // ans[n-i+1][j] = temp;
                    ans[n-i+1][n-j+1] = temp; 
                }
            }
        }
        for(int i=1;i<1001;++i){
            if( cont[i] == 1){
                ans[(n+1)/2][(n+1)/2] = i;
                break;
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if( ans[i][j] == -1){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
