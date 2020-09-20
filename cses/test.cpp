#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;

string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > DP(n, vector<int> (n, 0));
        int left = 0;
        int right = 0;
        int ans = 1;
        for( int i=0;i<n;++i) {
            DP[i][i] = 1;
             DP[i][i] = 1;
            if (i != n-1 && s[i] == s[i+1]){
                DP[i][i+1] = 2;
            }
            else if(i != n-1){
                DP[i][i+1] = 0;
            }
            if (i != n-1 && DP[i][i+1] > ans) {
                    ans = DP[i][i+1];
                    left = i;
                    right = i+1;
                }
        }
        
        for(int i=3;i<n+1;++i) {
           
            for(int j=i-1;j<n;++j) {
                
                int lower_end = j-i+1;
                // cout<<lower_end<<j<<endl;
                if( s[lower_end] == s[j] and DP[lower_end+1][j-1] == (j-lower_end-1)){
                    DP[lower_end][j] = j-lower_end +1;
                    // cout<<s[i]<<s[j]<<endl;
                    // return to_string(i);
                }
                else
                    DP[lower_end][j] = 0;
                if (DP[lower_end][j] > ans) {
                    ans = DP[lower_end][j];
                    left = lower_end;
                    right = j;
                }
            }
        }
        // cout<<left<<right<<endl;
        return s.substr(left, ans);
}


void merge_1(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n = B.size();
    auto iter = A.begin();
    int index = 0;
    for(int i=0;i<n;++i) {
        // cout<<*(iter)<<endl;
        while( B[i] > A[index] && index < int(A.size())) {
            index++;
        }
        // iter++;
        A.insert(A.begin() + index, B[i]);
        if( index == (A.size()-1)) {
            index++;
        }
    }
    for(int i : A)
        cout<<i<<endl;
    return;
}

class Test {
    int a;
    public:
    Test() {
        a = 2;
        cout<<this->get_a()<<endl;
    }
    int get_a() {
        return this->a;
    }
};

int getRich(long initialEnergy, vector<int> energy, vector<int> coins) {

    int n = coins.size();
    vector<int> sum(n+1,0);
    for(int i=n-1;i>=0;--i) {
        sum[i] = sum[i+1] + coins[i];
    }
    int ans = 0;
    if( initialEnergy >= n-1 )
        return sum[0];

    vector<int> temp;
    temp.push_back(int(initialEnergy+1));
    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    dp[0][int(initialEnergy+1)] = 0;
    for(int i=0;i<n;++i) {
        vector<int> t;
        for(int tt: temp) {

            // if( i == 0) {
            //     tt++;
            // }
            cout<<tt<<" "<<i<<endl;
            if( tt-1 >= 0)
            {
                t.push_back(tt-1);
                dp[i+1][tt-1] = dp[i][tt] + coins[i];
                cout<<"DP "<<i+1<<" "<<tt-1<<" "<<dp[i+1][tt-1]<<endl;
                ans = max(ans, dp[i+1][tt-1]);
            }
            int a = tt + energy[i] -1;    
            // if( i == 0) {
            //     a++;
            // }        
            if( a >= n-1-i) {
                ans = max(ans, sum[i+1] + dp[i][tt]);
            }
            else {
                t.push_back(a);
                dp[i+1][a] = dp[i][tt];
                cout<<"DP-2- "<<i+1<<" "<<a<<" "<<dp[i+1][a]<<endl;
            }
        }
        cout<<ans<<"asdfasd"<<endl;


        temp.clear();
        for(int j:t) {
            temp.push_back(j);
        }
    }
    return ans;
}
int main() {
   
    // Test a = Test();
    // cout<<a.get_a()<<endl;
    int n = 1;
    vector<int> e;
    e.push_back(1);
    e.push_back(5);
    e.push_back(3);
    e.push_back(3);
    e.push_back(1);
    vector<int> c;
    c.push_back(3);
    c.push_back(23);
    c.push_back(9);
    c.push_back(2);
    c.push_back(2);
    cout<<getRich(n, e, c)<<endl;

}