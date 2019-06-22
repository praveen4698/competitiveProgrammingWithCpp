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
const int lim = 1e6;
vector<int> A;

int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        A.clear();
        A.resize(n);
        for(int i=0;i<n;++i){
            scan(A[i]);
        }

        if( n&1 ){
            cout<<"NO"<<endl;
        }
        else{
            bool flag = true;
            for(int i=0;i<n/2;++i){
                int j = i+n/2;
                if( A[i] != -1 && A[j] != -1 ){
                    if( A[i] != A[j])
                        flag = false;
                }
                else if( A[i] == -1 && A[j] == -1  ){
                    A[j] = A[i] = 1;
                }
                else {
                    A[i] = A[j] = max(A[i],A[j]);
                }
            }
            if( flag ){
                cout<<"YES"<<endl;
                for(auto a:A)
                    printf("%d ",a);
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}
