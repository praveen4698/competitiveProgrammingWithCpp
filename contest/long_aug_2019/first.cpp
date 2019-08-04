#include<bits/stdc++.h>

using namespace std;

class Football {
    vector<int> A;
    vector<int> B;
    int n;
    public:
    Football(int n) {
        this->n = n;
        A.resize(n,0);
        B.resize(n,0);
    }

    ~Football() {
        A.clear();
        B.clear();
        // cout<<"hi"<<endl;
     }
    void takeinput() {
        for(int i=0;i<n;++i) {
            cin>>A[i];
        }
        for(int i=0;i<n;++i){
            cin>>B[i];
        }
    }

    int solve() {
        int ans = 0;
        for(int i=0; i<n;++i) {
            ans = max(ans,(A[i]*20)-(B[i]*10));
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
   
    while(t--) {
        int n;
        cin>>n;
        Football f(n);
        f.takeinput();
        cout<<f.solve()<<endl;
    
    }
    return 0;
}