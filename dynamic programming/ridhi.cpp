#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b) scanf("%d %d %d",&a,&b,&c)
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

    pii A[500001];
    int parent[500001];
    vpii edge_to_modified;
    int parenti(int a)
    {
        if( parent[a] == a)
            return a;
        parent[a]  = parenti(parent[a]);
        return parent[a];
    }
    void my_union(int x ,int y)
    {
        int fx = parenti(x);
        int fy = parenti(y);
        if( fx == fy)
            edge_to_modified.pb(mp(x,y));
        else
            parent[fx] = fy;
    }
    int main()
    {
        int n,m;
        scan(n);
        m = n-1; // number of edge;
        lp(i,0,n+1)
        {
            parent[i] = i;
        }
        lp(i,0,m)
        {
            int a,b;
            scan2(a,b);
            A[i].F = a;
            A[i].S = b;
            my_union(a,b);
        }
        int M = edge_to_modified.size();
        map<int,int> final_edge;
        int i = 0;
        lp(j,1,n+1)
        {
            int fj = parenti(j);
            final_edge[fj] = j;
        }
        map<int,int> ::iterator it;
        printf("%d\n",M);
        it = final_edge.begin();
        lp(i,0,M)
        {
            printf("%d %d %d %d\n",edge_to_modified[i].first,edge_to_modified[i].second,(*(++it)).second,(*(it)).second);

        }

        return 0;
    }
