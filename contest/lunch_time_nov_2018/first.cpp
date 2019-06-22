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
const int lim = 1e5+10;
vector<int> A[lim];
vector<int> primes;
void preprocess(){
    memset(A,0,sizeof(A));
    for(int i=2;i<lim;++i){
        if( A[i].size() == 0)
            for(int j=i;j<lim;j=j+i)
                A[j].push_back(i);
    }
   
}
int cont[lim];
int main()
{   
    int t;
    preprocess();
    scan(t);
    while(t--){
        int n;
        scan(n);
        memset(cont,0,sizeof(cont));
        int ans = 0;
        for(int i=0;i<n;++i){
            int a;
            scan(a);
            cont[a]++;
        }
       
        for(int i=2;i<lim;++i){
            int temp = 0;
            for(int j=i;j<lim;j = j+i){
                temp+=cont[j];
                
            }
            
            int aa = A[i].size();
            ans = max(ans,temp*aa);
        }
        print(ans);
    }
    return 0;
}
