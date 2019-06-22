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
const int lim = 1e6;
vector<int> fibo;
void pre_compute()
{
    fibo.pb(1);
    fibo.pb(2);
    for(int i=0;i<27;++i)
    {
        int n = fibo.size();
        fibo.pb(fibo[n-1]+fibo[n-2]);
        //cout<<fibo[n]<<endl;
    }
}
int A[lim],B[lim],ans[lim],value[lim],query[lim];
void pre_compute2()
{
    for(int i=1;i<lim;++i)
        value[i]= i;
    value[0] = 0;
    for(int i=0;i<lim;++i)
    {
        for(int j:fibo)
            if( i+j < lim)
                value[i+j] = min(value[i+j],value[i]+1);
    }
   // for(int i=1;i<30;++i)
   //     cout<<i<<" = "<<value[i]<<endl;
}
int func(int a,int k)
{
    if( value[a] <= k)
        return 1;
    else
        return 0;
}
int main()
{
    pre_compute();
    pre_compute2();
    int n,k;
    scan2(n,k);
    for(int i=0;i<n;++i)
        scan(A[i]);
    for(int i=0;i<n;++i)
        scan(B[i]);
    for(int i=0;i<n;++i)
        ans[i] = func(A[i],k);
    int q;
    scan(q);
    while(q--)
    {
        int a,b;
        scan2(a,b);
        query[a-1]++;
        query[b]--;
    }
    for(int i=0;i<n;++i)
    {
        if( i > 0)
            query[i]+=query[i-1];
        B[i] = B[i] + query[i]*ans[i];
    }
    scan(q);
    while(q--)
    {
        int a;
        scan(a);
        printf("%d\n",B[a-1]);
    }

    return 0;
}


