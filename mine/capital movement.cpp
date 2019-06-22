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
    const int lim = 1e5;
    bool visited[lim];
    map<int,int> M;
    priority_queue<int> Pq;
    queue<int> Q;
    vector<int> A[lim];
    int main()
    {
        lp(i,1,50001)
            visited[i] = false;
        int z;
        scan(z);
        while(z--)
        {
            int n;
            scan(n);
            lp(i,1,n+1)
            {
                int a;
                scan(a);
                M[a] = i;
                Pq.push(a);
            }
            lp(i,0,n-1)
            {
                int a,b;
                scan2(a,b);
                A[a].pb(b);
                A[b].pb(a);
            }
            lp(i,1,n+1)
            {
                visited[i] = true;
                vi::iterator it;
                for( it = A[i].begin(); it != A[i].end();++it)
                    visited[*it] = true;

                while(!Pq.empty())
                {
                    int t = Pq.top();
                    Pq.pop();
                    Q.push(t);
                    if( visited[M[t]] == false)
                    {
                        printf("%d ",M[t]);
                        break;
                    }
                    if( Pq.empty())
                    {
                        printf("0 ");
                    }

                }
                while(!Q.empty())
                {
                    Pq.push(Q.front());
                    Q.pop();
                }
                visited[i] = false;
                for( it = A[i].begin(); it != A[i].end();++it)
                    visited[*it] = false;
            }
            M.clear();
            while(!Pq.empty())
                Pq.pop();
            while(!Q.empty())
                Q.pop();
            lp(i,1,n+1)
                A[i].clear();

            printf("\n");
        }
        return 0;
    }


