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
    const int lim = 1e5+10;
    vector<pair<int,int> >  A[lim];

    	struct compare{
			bool operator()(const pair<int,ll > l,const pair<int,ll> r)
			{
				return l.S > r.S;
			}


		};
    int main()
    {
        ll *dist = new ll[lim];
        int *parent = new int[lim];
        int n,m;
        scan2(n,m);
        lp(i,0,n+1)
            parent[i] = -1,dist[i] = INFL;
        lp(i,0,m)
        {
            int a,b,c;
            scan2(a,b);
            cin>>c;
            A[a].pb(mp(b,c));
            A[b].pb(mp(a,c));
        }
        dist[1] = 0;
        priority_queue<pair<int ,ll> ,vector< pair< int ,ll > >,compare> Q;
        Q.push(mp(1,0));
        while(!Q.empty())
        {
            pii t = Q.top();
            Q.pop();
          //  printf("%d\n",t.S);
            int father = t.F;
            ll cost = t.S;
            vector< pair<int ,int > >::iterator i;
            for(i = A[father].begin();i != A[father].end();++i)
            {
                pair<int ,ll >  X = *i;
                int son = X.first;
                int weight = X.second;
                if( dist[son] > cost + weight)
                {
                    dist[son] = cost + (ll)weight;
                    parent[son] =father ;
                    Q.push(mp(son,dist[son]));
                }

            }
        }
        if( dist[n] == INFL)
        {
            printf("-1");
            return 0;
        }
        vector<int> temp;
        int i = (int)n;
        while( i != -1 )
        {
            temp.pb(i);
            i = parent[i];
        }
        vector<int>::reverse_iterator ir;
         for (ir = temp.rbegin(); ir != temp.rend(); ++ir)
        {
               ll t = (*ir);
               cout<<t;
               printf(" ");
           }

        return 0;
    }
