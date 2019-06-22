#include <bits/stdc++.h>

using namespace std;

int main() {


    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        int res = ( (n - 1) % 4 ) ^ ( (m - 1) % 3 );
        if (res == 0) {
            cout<<"Vanya"<<endl;
        }
        else {
            cout<<"Tuzik"<<endl;
        }
    }
    return 0;
}
