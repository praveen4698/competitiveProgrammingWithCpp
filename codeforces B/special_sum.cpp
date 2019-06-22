#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e3+10;

int special_sum(int a,int b,int c,int d)
{
    int ans = 0;
    ans+=2*abs(a+b-c-d);
    ans+=2*abs(a+c-b-d);
    ans+=2*abs(a+d-b-c);
    //ans+=abs(c+d-a-b);
    //ans+=abs(b+d-a-c);
    //ans+=abs(b+c-a-d);
    return ans;
}
int main()
{
    int A[lim];
    int t;
    scan(t);
    while(t--)
    {


        int n;
        scan(n);
        for(int i=0;i<n;++i)
            scan(A[i]);
        int ans = 0;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                for(int k=j+1;k<n;++k)
                    for(int l=k+1;l<n;++l)
                        ans+=special_sum(A[i],A[j],A[k],A[l]);
        cout<<ans<<endl;
    }
    return 0;
}


