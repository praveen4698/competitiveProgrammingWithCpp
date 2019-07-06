#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        mss A;
        string S[3001];
        int n,m;
        scanf("%d %d",&n,&m);
        lp(i,0,m)
        {
            string a,b;
            cin>>a>>b;
            A[a] = b;
        }
        lp(i,0,n)
            cin>>S[i];
        lp(i,0,n)
        {
            if( S[i].length() > A[S[i]].length())
                cout<<A[S[i]];
            else
                cout<<S[i];
            if( i < n-1)
                printf(" ");
        }

        return 0;
    }

