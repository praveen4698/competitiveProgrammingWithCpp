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
const int lim = 1e5+10;
vector<int> A;
int h[lim];
int ans[lim];
int main()
{
    memset(ans,-1,sizeof(ans));
    int n;
    scan(n);
    for(int i=1;i<=n;++i){
        int a;
        scan(a);
        h[a] = i;
    }
    ans[h[n]] = 2;
    A.push_back(h[n]);
    for(int i=n-1;i>=1;--i){
        
        int flag = false;
        for(int j=h[i]+i;j<=n;j=i+j){
            if( ans[j] == 2){
                flag = true;
                break;
            }
        }
        if( flag == false){
            for(int j=h[i]-i;j>0;j=j-i){
                if( ans[j] == 2)
                    {
                        flag = true;
                        break;
                    }
            }
        }
        // cout<<i<<flag<<endl;
        if( flag == true ){
            ans[h[i]] = 1;
        }
        else{
            A.push_back(h[i]);
            ans[h[i]] = 2;
        }
    } 
    for(int i=1;i<=n;++i){
        if( ans[i] == 1){
            cout<<"A";
        }
        else
            cout<<"B";
    }
    return 0;
}
