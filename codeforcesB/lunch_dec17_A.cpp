#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
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
//"mon", "tues", "wed", "thurs", "fri", "sat" or "sun
map<string,int> M;
int main()
{
    M["mon"] = 1;
    M["tues"] = 2;
    M["wed"] = 3;
    M["thurs"] = 4;
    M["fri"] = 5;
    M["sat"] = 6;
    M["sun"] = 7;
    int t;
    S(t);
    while(t--)
    {
        int n;
        string s;
        S(n);
        cin>>s;
        int start = M[s];
        int ans[8] ;
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;++i)
        {
            ans[start]++;
            start++;
            if( start > 7)
                start = 1;
        }
        for(int i=1;i<8;++i)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}


