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


int main()
{
    int n;
    scan(n);
    int pt=0,px = 0,py = 0,flag = 0 ;
    for(int i=0;i<n;++i)
    {
        int t,x,y;
        scan3(t,x,y);
        if( flag == 0)
        {
            int delt = t - pt;
            if( delt < 0)
                flag = 1;
            int dis = abs(x-px)+abs(y-py);
            if( dis > delt )
                flag = 1;
            else if(delt > dis)
            {
                int tt = delt - dis ;
                if( tt%2  == 1)
                    flag = 1;
            }
        }
        pt = t;
        px = x;
        py = y;
    }
    if( flag == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


