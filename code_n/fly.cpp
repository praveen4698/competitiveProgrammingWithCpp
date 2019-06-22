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
int A[lim],B[lim];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>A[i];
    for(int i=0;i<n;++i)
        cin>>B[i];
    double ans = 1.00*m;
    int flag = 0;
    if( B[0] == 1 || A[0] == 1)
        flag = 1;
    if( flag == 1){
        cout<<"-1"<<endl;
        return 0;
    }
    ans = ans + (ans*1.00)/(1.00*(B[0]-1.00));
    for(int i=n-1;i>0;i--){

        if( A[i] == 1 || B[i] == 1)
        {
            flag = 1;
            break;
        }

        ans = ans + (ans*1.00)/(1.00*(A[i]-1.00));
        ans = ans + (ans*1.00)/(1.00*(B[i]-1.00));
    }
    ans = ans + (ans*1.00)/(1.00*(A[0]-1.00));
    if( flag == 1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<setprecision(10)<<(ans-1.00*m)<<endl;
    }
    return 0;
}