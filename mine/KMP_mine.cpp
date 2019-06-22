#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
string pattern, text;
//int lps[lim];
vector<int> lps_array(string &pattern){
    
    int n = pattern.size();
    vector<int> lps(n);
    for (int i = 1; i < n; ++i){
        int j = lps[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = lps[j - 1];
        lps[i] = j + (pattern[i] == pattern[j]);
    }
    return lps;
}

void KMP(){
    
    int m = pattern.size();
    int n = text.size();
    vector<int> lps = lps_array(pattern);
    int i=0;
    int j=0;
    while(i<n){
        if( pattern[j] == text[i])
            i++,j++;
        if( j == m){
            cout<<"found"<<endl;
            j = lps[j-1];
        }
        else if( i < n && pattern[j] != text[i]){
            if( j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return ;
}
int main(){
    text = "ABABDABACDABABCABAB";
    pattern  = "ABABCABAB";
    cout<<text<<endl;
    KMP();
    return 0;
}


