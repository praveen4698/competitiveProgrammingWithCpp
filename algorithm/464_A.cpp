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

const int lim = 1e5+10;
int A[lim];
int main()
{
    int n;
    scan(n);
    for(int i=1;i<n+1;++i)
        scan(A[i]);
    int flag = 0;
    for(int i=1;i<n+1;++i)
    {
        int a = i;
        int b = A[i];
        int c = A[b];
        if( a == A[c])
        {
            flag = 1;
        }
    }
    if(flag == 1)
        printf("YES\n");
    else
        printf("No\n");
    return 0;
}


