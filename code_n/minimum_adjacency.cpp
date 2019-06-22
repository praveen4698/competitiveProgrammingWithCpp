
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
const int lim = 1e5+10;
map<int,int> M;
set<int> S;
int A[lim];
int main()
{
    int n,q;
    scan2(n,q);
    int ans = INF;
    for(int i=0;i<n;++i){
        cin>>A[i];
        if( i > 0){
            M[abs(A[i]-A[i-1])]++;
            ans = min(ans, abs(A[i]-A[i-1]));
            S.insert(abs(A[i]-A[i-1]));
        }
    }
    while(q--){
        int a;
        cin>>a;
        if( a == 0){
            int b,c;
            cin>>b>>c;
            b--;
            if( b == 0){
                int temp = abs(A[b]-A[b+1]);
                M[temp]--;
                if(M[temp] == 0){
                    S.erase(temp);
                }
                A[b] = c;
                temp = abs(A[b]-A[b+1]);
                M[temp]++;
                S.insert(temp);
            }
            else if( b == n-1){
                int temp = abs(A[b]-A[b-1]);
                M[temp]--;
                if(M[temp] == 0){
                    S.erase(temp);
                }
                temp = abs(A[b]-A[b-1]);
                M[temp]++;
                
            }
            else{

            }
        }
    }
    return 0;
}


