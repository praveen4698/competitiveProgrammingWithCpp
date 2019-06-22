#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vpii A[100001];
    bool mark[100001];
    int main()
    {   int n,m,k;
        scan2(n,m);
        scan(k);
        lp(i,1,n+1)
            mark[i] = false;
        lp(i,0,m)
        {
            int a,b,c;
            scan2(a,b);
            scan(c);
            A[a].pb(mp(b,c));
            A[b].pb(mp(a,c));
        }
        queue<int> Q;
        lp(i,0,k)
        {
            int a;
            scan(a);
            Q.push(a);
            mark[a] = true;
        }
        ll mini = INFL;
        while(!Q.empty())
        {
            int t = Q.front();
            Q.pop();
            vpii::iterator it;
            for(it = A[t].begin();it != A[t].end();++it)
            {
                int des = (*it).first;
                int weight = (*it).second;
                if( mark[des] == false && mini > (ll)weight)
                    mini = (ll)weight;
            }
        }
        if( mini == INFL)
            printf("-1");
        else
            printf("%lld\n",mini);

        return 0;
    }
