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
int A[lim];
int B[lim];
int ans[lim];
vi res;

int main()
{
    int n;
    scan(n);
    for(int i=1;i<n+1;++i)
        scan(A[i]);
    for(int i=1;i<n+1;++i)
        scan(B[i]);
    for(int i=1;i<n+1;++i)
    {
        res.clear();
        for(int j=1;j<A[i]+1;++j)
        {
            res.pb(j);
            ans[j] = 0;
        }
        random_shuffle(all(res));
        for(int j=0;j<B[i];++j)
            ans[res[j]] = 1;
        for(int j=1;j<A[i]+1;++j)
        {
            if( ans[j] == 1)
                printf("b");
            else
                printf("w");
        }
        cout<<endl;


    }
    res.clear();
    for(int i=1;i<n+1;++i)
        res.pb(i);
    //random_shuffle(all(res));
    for(auto i:res)
        printf("%d ",i);
    cout<<endl;
    return 0;
}


