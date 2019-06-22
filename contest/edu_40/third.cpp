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

const int lim = 2e5+10;
int A[lim];
int main()
{
    int n;
    scan(n);
    int element = -1;
    int maxi = -1;

    for(int i=0;i<n;++i)
        cin>>A[i];

    element = A[0];
    if( n == 1)
    {
        cout<<"YES"<<endl;
        cout<<element<<" 1"<<endl;
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        element = max(A[i],element);
        maxi = max(abs(A[i]-A[i-1]),maxi);
    }
    int flag = 0;
    for(int i=1;i<n;++i)
    {
        int diff = abs(A[i]-A[i-1]);
        if( diff == 1 || diff == maxi)
            continue;
        else
            flag = 1;
        if( A[i] <= 0 || A[i-1] <= 0)
            flag = 1;
    }
    int x = element;
    int y = maxi;
    for(int i=1;i<n;++i)
    {
        int diff = abs(A[i]-A[i-1]);
        if( diff == 0)
            flag = 1;
      //  cout<<diff<<" "<<A[i]/y<<" "<<A[i-1]/y<<endl;
        if( (diff == 1) && (A[i]-1)/y != (A[i-1]-1)/y && (y != 1))
            flag = 1;
    }
    if( flag == 1)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<element<<" "<<maxi<<endl;
    }
    return 0;
}


