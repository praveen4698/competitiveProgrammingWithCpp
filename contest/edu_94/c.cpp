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
        string s;
        cin>>s;
        int x;
        // cout<<"Hi there"<<endl;
        // fflush(stdin);
        cin>>x;
        // fflush(stdin);
        int n = s.size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;++i) {
            if( s[i] == '0') {
                if( i-x >= 0)
                    ans[i-x] = 0;
                if( i+x < n)
                    ans[i+x] = 0;   
            }
        }
        // for(int i=0;i<n;++i) {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        int flag = 1;
        for(int i=0;i<n;++i) {

            if( s[i] == '1') {
                bool done = true;
                if( i-x >= 0) {
                    if( ans[i-x] == -1 || ans[i-x] == 1) {
                        ans[i-x] = 1;
                        done = false;
                    }
               }

               if( done && i+x < n) {
                   if( ans[i+x] == -1 || ans[i+x] == 1) {
                       ans[i+x] = 1;
                       done = false;
                   }
               }
            //    cout<<i<<endl;
               if( done) {
                   flag = -1;
                   break;
               }
            }
        }

        if( flag == -1) {
            cout<<"-1"<<endl;
        }
        else {
            for(int i=0;i<n;++i) {
                if( ans[i] == 0) {
                    cout<<"0";
                }
                else {
                    cout<<"1";
                }
            }
            cout<<endl;
        }
        // cout<<t<<endl;
    }
    return 0;
}
