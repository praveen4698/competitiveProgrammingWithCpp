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
vector<int> A;
int solve(int l,int r,int depth){
    if( depth > 100)
        return INF;
    if( l > r)
        return 0;
    int maxi = -1;
    int index = -1;
    for(int i=l;i<=r;++i){
        if(A[i] > maxi){
            maxi = A[i];
            index = i;
        }
    }
    vector<int> in;
    for(int i=l;i<=r;++i){
        if( A[i] == maxi)
            in.push_back(i);
    }
    int ans = INF;
    for(int i:in){
        int temp  = min(solve(l,i-1,depth+1),solve(i+1,r,depth+1));
        ans = min(ans,1+temp);
    }
    return ans;

}

int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        A.clear();
        A.resize(n);
        for(int i=0;i<n;++i)
            scan(A[i]);
        printf("%d\n",solve(0,n-1,1));
    }

    return 0;
}


