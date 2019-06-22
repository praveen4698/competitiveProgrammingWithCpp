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

const int lim = 1e6+10;
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
int sum[lim];
int cont[lim];
int main()
{
    preprocess();
    memset(sum,0,sizeof(sum));
    for(auto a: primes){
        for(int i=a;i<lim;i+=a){
            sum[i]+=a;
        }
    }
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        memset(cont,0,sizeof(cont));
        for(int i=0;i<n;++i){
            int a;
            scan(a);
            cont[a]++;
        }
        ll ans = 0ll;
        for(int i=2;i<lim;++i){
            if( cont[i] == 0)
                continue;
           // printf("%d %d sum \n",i,sum[i]);
            ans = ans + cont[i]*1ll*(cont[i]-1);
            for(int j=2*i;j<lim;j=j+i){
                if( cont[j] > 0 && sum[j]%sum[i] == 0){
                    ans = ans + cont[i]*1ll*cont[j];
                   // printf(" %d %d %d\n",i,j,ans);

                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
