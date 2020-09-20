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
        vector<int> sub_array;
        int count = 0;
        for(int i=0;i<n;++i) {
            int a;
            cin>>a;
            if( a == 0){
                count++;
            }
            else {
                if( count > 0) {
                    sub_array.push_back(count);
                }
                count = 0;
            }
        }

        sort(sub_array.begin(), sub_array.end());
        reverse(sub_array.begin(), sub_array.end());

        if( sub_array.size() == 0) {
            cout<<"No"<<endl;
        }
        else if( sub_array.size() == 1) {
            if( sub_array[0]%2 == 0) {
                cout<<"No"<<endl;
            }
            else {
                cout<<"Yes"<<endl;
            }

        }
        else {
            if( sub_array[0]%2 == 0) {
                cout<<"No"<<endl;
            }
            else if( sub_array[0]/2 < sub_array[1] ) {
                cout<<"No"<<endl;
            }
            else {
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}
