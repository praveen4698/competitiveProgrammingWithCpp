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

int solve(int n,int mul){

    if( n == 1){
        cout<<mul;
        return 0;
    }
    if( n == 2){
        cout<<mul<<" "<<2*mul;
        return 0;
    }
    if( n == 3){
        cout<<mul<<" "<<mul<<" "<<3*mul;
        return 0;
    }
    int t = n/2;
    n = n/2 + n%2;
    for(int i=0;i<n;++i)
        cout<<mul<<" ";

    solve(t,2*mul);
}

int main()
{
    int n;
    scan(n);
    solve(n,1);
    return 0;
}


