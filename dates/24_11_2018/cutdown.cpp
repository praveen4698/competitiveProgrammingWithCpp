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
const int lim = 200001;

int cont[lim];
int k;
bool check(int t){

    int temp = 0;
    for(int i=0;i<lim;++i)
        temp+=cont[lim]/t;
    return (temp>=k);
}
int main()
{
    int n;
    scan2(n,k);
    memset(cont,0,sizeof(cont));
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        cont[a]++;
    }
    int l = 0;
    int r = n;
    vector<int> ans;
    while(l<r){
        int mid = (l+r+1)/2;
        if( check(mid)){
            l = mid;
        }
        else
            r = mid-1;
    }
    for(int i=0;i<lim;++i){
        for(int j=0;j<cont[i]/l;++j){
            ans.push_back(i);
            if(ans.size() == k)
                break;
        }
        if( ans.size() == k)
            break;
    }
    for(int i:ans){
        printf("%d ",i);
    }
    

    return 0;
}
