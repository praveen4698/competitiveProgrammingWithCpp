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
    int t;
    scan(t);
    while(t--)
    {
        int n,k,s;
        scan3(n,k,s);
        int sum = k*s;
        int flag = 0;
        int temp = 0;
        int cont = 0;
        int ans = -1;

        for(int i=1;i<=s;++i)
        {
            if( i%7 == 0)
            {
                if( temp < i*k)
                {
                    flag = 2;
                    break;

                }
                if( flag == 2)
                    break;
                continue;
            }

            temp+=n;
            if( temp < i*k)
            {
                break;
            }
            cont++;
            if(temp >= sum)
            {
                ans = cont;
                flag = 1;
                break;
            }
        }
        if( flag == 1)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}


