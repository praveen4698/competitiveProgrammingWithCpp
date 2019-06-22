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
int A[lim];
map<int,int> M;
int main()
{
    int t;
    scan(t);
    while(t--){
        M.clear();
        int n,z1,z2;
        scan3(n,z1,z2);
        for(int i=0;i<n;++i){
            scan(A[i]);
            M[A[i]] = 1;
            M[-1*A[i]] = 1;

         }
         if( M[z1] == 1 || M[z2] == 1){
            printf("1\n");
            continue;
         }

         int flag = 1;
         for(int i=0;i<n;++i){
            int flag1 = 0;
            for(int j=0;j<n;++j){
                int n1 = A[i];
                int n2 = -A[i];
                int x1 = n1 - A[j];
                int x2 = n1 + A[j];
                int x3 = n2 -A[j];
                int x4 = n2 + A[j];
                bool t1 = x1 == z1 || x1 == z2 || x2 == z1 || x2 == z2;
                bool t2 = x3 == z1 || x3 == z2 || x4 == z1 || x4 == z2;
                if( t1 && t2 )
                    flag1 = 1;
            }
            if( flag1 == 0){
                flag = 0;
                break;
            }
         }
         if( flag == 1){
            printf("2\n");
         }
         else{
            printf("0\n");
         }
    }
    return 0;
}


