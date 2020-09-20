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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count = 0;
        for(auto i: s) {
            if( i == '1')
                count++;
        }
        if( count >= n) {
            for(int i=0;i<n;++i)
                cout<<"1";
        }
        else {
            for(int i=0;i<n;++i)
                cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}
