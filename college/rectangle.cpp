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
const int lim = 1e6 + 10;
int A[lim];
vector<int> temp;
int main()
{
    int t;
    scan(t);
    while(t--)
    {
       ll n,k;
       temp.clear();
       scanf("%lld %lld",&k,&n);
       for(int i=0;i<=n;++i)
            A[i] = -1;
       A[k] = 2;
       ll sum = n*1ll*(n+1);
       sum/=2;
       sum = sum - 1ll*k;
       if(sum%2 == 1)
            printf("impossible\n");
       else
       {
           ll req = (1ll*sum)/2;
           //cout<<req<<endl;
           temp.clear();
           for(int i=1;i<=n;++i)
                if( i != k)
                    temp.pb(i);
           for(int i=0;i<1000;++i)
           {
               for(int j =1;j<=n;++j)
               {
                   A[j] = -1;
                   if(j == k)
                    A[j] = 2;
               }
               ll re = req;
               random_shuffle(all(temp));
               for(int j:temp)
               {
                   if( j <= re)
                   {
                       re-=j;
                       A[j] = 1;
                   }

               }
               if( re == 0)
               {
                   req = 0ll;
                   break;
               }
           }
           if( req > 0 )
               printf("impossible\n");
           else
           {
               for(int i=1;i<=n;++i)
                {
                    if( A[i] == -1)
                        cout<<0;
                    else
                        cout<<A[i];
                }
               cout<<endl;
           }
       }


    }
    return 0;
}


