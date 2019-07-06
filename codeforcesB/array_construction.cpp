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
int C[300][300];
int mark[300];


int main()
{
    int n,m;
    memset(mark,0,sizeof(mark));
    scan2(n,m);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scan(C[i][j]);
    ll sum = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            sum+=C[i][j];
    }
    ll avg = sum/(n*n);
    int cont = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if( C[i][j] > avg)
            {
                mark[i] = 1;
                mark[j] = 1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if( i == 0)
            cout<<m<<" ";
        else
            cout<<"0"<<" ";
    }
    return 0;
}



