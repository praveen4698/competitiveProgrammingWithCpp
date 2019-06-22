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

const int lim = 1001;
string S[lim];
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,m;
        scan2(n,m);
        for(int i=0;i<n;++i){
            cin>>S[i];
        }
        bool flag = true;
        for(int i=0;i<n;++i){
            bool temp = false;
            for(int j=0;j<m;++j){
                temp = false;
                if( S[i][j] == '#'){
                    continue;
                }
                if( i > 0 && j > 0){
                    if( S[i-1][j-1] == '.' && S[i-1][j] == '.' && S[i][j-1] == '.')
                        temp = true;
                }
                if( i > 0 && j < m-1){
                    if( S[i-1][j+1] == '.' && S[i-1][j] == '.' && S[i][j+1] == '.')
                        temp = true;
                }
                if( i < n-1 && j < m-1){
                    if( S[i+1][j+1] == '.' && S[i+1][j] == '.' && S[i][j+1] == '.')
                        temp = true;
                }
                if( i < n-1 && j > 0){
                    if( S[i+1][j-1] == '.' && S[i+1][j] == '.' && S[i][j-1] == '.')
                        temp = true;
                }
                if( temp == false){
                    flag = false;
                    break;
                }
                
            }
            if( flag == false){
                break;
            }
        }
        if( flag == true){
            cout<<"YES"<<endl;

        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
