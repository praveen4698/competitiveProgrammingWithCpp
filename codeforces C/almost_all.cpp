#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;
const ll mod = 998244353;

class solve{

        int n;
        vector<long long > A;
    
    public:
        solve(int num) {
            n = num;
            A.resize(n,0);
            
        }
        ~solve() {
            A.clear();
        }
        int size() const { return n;}
        friend istream & operator >> (istream &in, solve &s);
        friend ostream & operator << (ostream &out, const solve &s);
        long long  ans() {
            sort(A.begin(),A.end());
            long long x = A[0]*1ll*A[n-1];
            vector<long long> B;
            for(int i=2;i*1ll*i<=x ; ++i){
                if( x%i == 0){
                    B.push_back(i);
                    if( x/i != i){
                        B.push_back(x/i);
                    }
                }
            }
            sort(B.begin(),B.end());
            if( A== B) {
                return x;
            }
            else 
                return -1;
        }

};

istream& operator>> (istream &in, solve &s) {
    for(int i=0;i<s.size();++i)
        in>>s.A[i];
}

ostream& operator<< (ostream &out, const solve &s){
    for(int i=0;i<s.size();++i)
        out<<s.A[i]<<" ";
}


int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        solve x(n);
        cin>>x;
        cout<<x.ans()<<endl;

    }
    return 0;
}
