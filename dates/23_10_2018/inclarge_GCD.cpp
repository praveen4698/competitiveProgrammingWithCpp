#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1.5e7+10;
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
int M[lim];
vector<int> AA;
int main(){
    int n;
    scan(n);
    preprocess();
    // M.resize(n);
    // printf("dsaf");
     memset(M,0,sizeof(M));
     int d = 0;
     AA.resize(n);
    for(int i=0;i<n;++i){
        int a;

        scan(AA[i]);
        if( d == 0)
            d = AA[i];
        else
            d = __gcd(d,AA[i]);
    }
    for(int i=0;i<n;++i){
        M[AA[i]/d]++;
    }
   int ans = -1;
    for(int a:primes){
        int cont = 0;
        // cout<<a<<endl;
        for(int j=a;j<lim;j = j+a){
            cont+=M[j];
        }
        if( cont == n)
            continue;
        if( cont != 0){
            ans = max(ans,cont);
        }
        
    }
    if( ans == -1){
        cout<<ans<<endl;
        return 0;
    }

    cout<<(n-ans)<<endl;

    return 0;
}

