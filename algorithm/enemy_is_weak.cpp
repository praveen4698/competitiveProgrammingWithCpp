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
const int lim = 1e6+10;
int bit[2][lim+1];
void update(int index,int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[index][x] += val;
}
int query(int index,int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[index][x];
     return sum;
}
int A[lim];
map<int,int> M;
int main()
{
    clock_t start = clock();
    int n;
    scan(n);
    memset(bit,0,sizeof(bit));
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        M[A[i]] = 0;
    }
    int maxi = 1;
   // cout<<"saf"<<endl;
    map<int,int>::iterator it;
    for(it = M.begin();it!=M.end();++it)
    {
        M[it->first] = maxi;
        maxi++;
    }
   // cout<<"sfasfsadf:"<<endl;

    for(int i=0;i<n;++i)
        update(0,M[A[i]],1);
    ll ans = 0;
   // cout<<"dfasf"<<endl;
    for(int i=n-1;i>=0;--i)
    {
        int l = i - query(0,M[A[i]]) +1;
        int r = query(1,M[A[i]]-1);
        ans += (l*1ll*r);
        update(0,M[A[i]],-1);
        update(1,M[A[i]],1);
    }
    cout<<ans<<endl;
    clock_t end = clock();
    cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    return 0;

}


