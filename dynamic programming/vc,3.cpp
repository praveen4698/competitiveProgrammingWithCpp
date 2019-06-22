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
    const int lim = 1e4 + 10;
    bool visited[lim];
    vi A[lim];

    int main()
    {
        int n;
        scan(n);
        lp(i,1,n+1)
        {
            int a;
            scan(a);
            A[i].pb(a);
            A[a].pb(i);
            visited[i] = false;
        }
        int counti = 0;
        queue<int> Q;
        lp(i,1,n+1)
        {
            if(visited[i] == false)
            {
                counti++;
                Q.push(i);
                while(!Q.empty())
                {
                    int t = Q.front();
                    Q.pop();
                    if(visited[t] == true)
                        continue;
                    visited[t] = true;
                    vi::iterator it;
                    for( it = A[t].begin();it != A[t].end();++it)
                    {
                        if( visited[*it] == false)
                            Q.push(*it);
                    }

                }
            }

        }
        printf("%d\n",counti);
        return 0;
    }
