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
        ll k,d0,d1;
        cin>>k>>d0>>d1;
     //   cin>>k>>d0>>d1;
        ll sum = d0+d1;
        ll j = -1;
        d1 = (d1+d0)%10;
        if(d1 == 0 || d1 == 5)
        {
            if( d1 == 5)
                sum+=5;
            if( sum%3 == 0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;
        }

        for(int i=0;i<min(k-2,100ll);++i)
        {
            if( i > 0)
                d1 = (2ll*d1)%10;
            if( d1 == 2ll)
            {
                j = 1ll*i;
                break;
            }
            sum+=d1;
            //d1 = (2*d1)%10;
        }
      //  cout<<sum<<endl;
        if( j == -1)
        {
            if( sum%3 == 0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;
        }
        j = j+2;
        sum = sum + ((k-j)/4)*20;
        ll rem = (k-j)%4;
        if( rem >= 1)
            sum+=2;
        if( rem >= 2)
            sum+=4;
        if( rem >= 3)
            sum+=8;
        if( sum%3 == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}


