#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        int count = n/k;
        string s;
        cin>>s;
        int zero = 0;
        int one = 0;
        for(char a: s) {
            if( a == '1')
                one++;
            else
            {
                zero++;
            }
            
        }
        if( zero%count > 0 || one%count > 0){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else {
            zero = zero/count;
            one = one/count;
            for(int i=0;i<count;++i) {
                if( i%2 == 0) {
                    for(int j=0;j<zero;++j)
                        cout<<"0";
                    for(int j=0;j<one;++j)
                        cout<<"1";
                }
                else {
                    for(int j=0;j<one;++j)
                        cout<<"1";
                    for(int j=0;j<zero;++j)
                        cout<<"0";
                }
                
            }
            cout<<endl;
        }

    }
    return 0;
}
