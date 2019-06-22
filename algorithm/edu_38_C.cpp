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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll lim = 2e9+10;
unordered_map<int,int> M;

int main()
{
    for(int i=1;i*i<lim;++i)
        M[i*i] = 1;
    int t;
    scan(t);
    while(t--)
    {
        int x;
        int n ,m;
        scan(x);
        int flag = 0;
        for(int i=1;i*i<lim;++i)
        {
            if( i*i >= x)
            {
                int temp = i*i - x;
              // cout<<temp<<endl;
                if(M[temp] == 1)
                {
                    n = i;
                    m = n/sqrt(temp);
                    if( n/m == sqrt(temp))
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if( flag == 1)
            cout<<n<<" "<<m<<endl;
        else
            cout<<"-1"<<endl;
    }

    return 0;
}


