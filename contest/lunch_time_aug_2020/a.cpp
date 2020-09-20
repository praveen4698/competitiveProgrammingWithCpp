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
        int n, m;
        cin>>n>>m;
        vector<vector<int> > rating(n, vector<int> (m+1, 0));
        for(int i=0;i<n;++i) {
            cin>>rating[i][0];
        }
        vector<int> peak_rating_month(n, 0);
        vector<int> peak_rating(n, 0);
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                int a ;
                cin>>a;
                rating[i][j+1] = rating[i][j] + a;
                if( peak_rating[i] < rating[i][j+1]) {
                    peak_rating[i] = rating[i][j+1];
                    peak_rating_month[i] = j+1;
                }
            }
        }

        vector<int> peak_ranking(n,INT_MAX);
        vector<int> peak_ranking_month(n, 0);
        vector<int> temp;
        for(int i=1; i<m+1; ++i){
            temp.clear();
            for(int j=0;j<n;++j) {
                temp.push_back(rating[j][i]);
            }
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());

            for(int j=0;j<n;++j) {
                int current_rating = rating[j][i];
                int ans = 0;
                for(int k=0;k<n;++k) {
                    if( current_rating == temp[k] ) {
                        ans = k+1;
                        break;
                    }
                }
                if( peak_ranking[j] > ans) {
                    peak_ranking[j] = ans;
                    peak_ranking_month[j] = i;
                }
            }
        }

        int ret = 0;
        for(int i=0;i<n;++i) {
            if( peak_ranking_month[i] != peak_rating_month[i])
                ret++;
        }

        cout<<ret<<endl;
    }
    return 0;
}
