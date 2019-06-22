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

const int lim = 1e3;
int A[lim];
vector<int> primes;
void preprocess(){
    memset(A,0,sizeof(A));
    for(int i=2;i<lim;++i){
        if(A[i] == 0){
            for(int j=2*i;j<lim;j=j+i)
                A[j] = 1;
        }
    }
    for(int i=2;i<lim;++i)
        if(A[i]==0)
            primes.push_back(i);
}
vector<int> B;
map<int,vector<int> > C;
int main()
{
    preprocess();
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        B.clear();
        B.resize(n);
        for(int i=0;i<n;++i){
            scan(B[i]);
        }
        

    }
    return 0;
}
