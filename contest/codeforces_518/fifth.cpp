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
const int lim = 1e3;
int parent[lim];
int par(int x){
    if( parent[x] == -1)
        return x;
    else {
        return parent[x] = par(parent[x]);
    }
}
int x[lim],y[lim];
int start[lim];
int main()
{
    int n,m;
    scan2(n,m);
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<m;++i){
        int a,b;
        scan2(a,b);
        int fa = par(a);
        int fb = par(b);
        if( fa == fb)
            continue;
        parent[fa] = fb;
    }
    int cont = 1;
    for(int i=0;i<=n;++i){
        start[i] = cont;
        cont+=5000;
    }
    for(int i=1;i<n+1;++i){
        int fa = par(i);
        x[i] = fa;
        y[i] = start[fa];
        start[fa]++;

    }
    for(int i=1;i<=n;++i){
        print(1);
        printf("%d %d\n",x[i],y[i]);

    }
    return 0;
}
