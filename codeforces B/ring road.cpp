#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        //ll A(123456);
        ll n,m;
        cin>>n>>m;
        int i;
        ll count = 0;
        ll prev = 1;
        loop(i,0,m)
        {
            ll a;
            cin>>a;
            count = count + a - prev;
            if( (a - prev) < 0)
            {
                count = count + n;
            }
            prev = a;
            //cout<<count<<"\n";
        }
        cout<<count;
        return 0;
    }
