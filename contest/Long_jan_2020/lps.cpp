#include<bits/stdc++.h> 

using namespace std;
vector<int> convertToNewString(const vector<int> &s) {
    // string newString = "@";
    // @ -> -1
    // # = -2
    // $ -3
    vector<int> newString;
    newString.push_back(-1);
    for (int i = 0; i < s.size(); i++) {
        newString.push_back(-2);
        newString.push_back(s[i]);
        // newString += "#" + s.substr(i, 1);
    }

    // newString += "#$";
    newString.push_back(-2);
    newString.push_back(-3);
    return newString;
}
vector<int> lps_array(const vector<int> &s) {
    int c = 0, r = 0;  
    vector<int> Q = convertToNewString(s);         // current center, right limit
    vector<int> P(2*s.size()+4);
    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }
    vector<int> ans;
    int n = s.size();
    // for(int i=0;i<P.size();++i) {
    //     cout<<P[i]<<" ";
    // }    
    // cout<<endl;
    for(int i=0; i<n;++i){
        ans.push_back( P[2*i + 2]);
        // cout<<ans[i]<<endl;
    }
    return ans;
}


int main() {
    
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        vector<vector<int> > lps_row, lps_column;
        vector<vector<int> > row(n), col(m);
        for( int i=0;i<n;++i) {
            // row.push_back(vector<int>());
            for(int j=0;j<m;++j) {
                if( i ==0) {
                    // col.push_back(vector<int> ());
                }
                int a;
                cin>>a;
                col[j].push_back(a);
                row[i].push_back(a);
                // printf("%d %d\n", i , j);
            }
        }

        for(int i=0;i<n;++i) {
            
            
            lps_row.push_back(lps_array(row[i]));
        }
        for(int i=0;i<m;++i){
            // vector<int> temp = lps_array(col[i]);
            // for(int j=0;j<n;++j) {
            //     cout<<temp[j]<<" ";
            // }
            // cout<<endl;
            lps_column.push_back(lps_array(col[i]));
        }

        int ans = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                int x = min(lps_row[i][j], lps_column[j][i]);
                ans = ans + x/2 + 1;
            }
        }
        cout<<ans<<endl;
    }

}