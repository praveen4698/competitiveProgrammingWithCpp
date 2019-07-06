#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string h = "hello";
        string in;
        cin>>in;
        int n = in.length();
        int j = 0;
        lp(i,0,n)
        {
            if( h[j] == in[i])
                j++;
            if( j == 5)
                break;

        }

        if( j == 5)
            cout<<"YES";
        else
            cout<<"NO";

        return 0;
    }

