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

const int lim = 1e6;
int P[lim];
vector<int> primes;
void preprocess(){
    memset(P,0,sizeof(P));
    for(int i=2;i<lim;++i){
        if(P[i] == 0){
            for(int j=i;j<lim;j=j+i)
                P[j] = i;
        }
    }
    for(int i=2;i<lim;++i)
        if(P[i]==i)
            primes.push_back(i);
}
int main()
{
    preprocess();
    int n;
    scan(n);
    int ans = 1;
    vector<int> A;
    if( n == 1)
    {
        printf("1 0\n");
        return 0;
    }
    int maxi = -1;
    for(int p:primes){
        
        int temp = 0;
        while(n%p == 0){
            n/=p;
            temp++;
        }
        if( temp > 0){
            ans*=p,maxi = max( temp,maxi);
        A.push_back(temp);
        }
    }
    sort(all(A));
    int two = 1;
    int u = 0;
    while(two<maxi){
        two*=2;
        u++;
    }
    // cout<<maxi<<two<<endl;
    if( maxi == two){
        int cont = 0;
        for(int a:A)
            if( a == maxi)
                cont++;
        int t = A.size();
        if( t == cont)
            u--;
    }
    u++;
    cout<<ans<<" "<<u<<endl;
    return 0;
}
