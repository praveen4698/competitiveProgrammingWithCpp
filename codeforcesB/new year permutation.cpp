#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
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
    int parent[301];
    int find_parent(int x)
    {
        if( x == parent[x])
            return x;
        parent[x] = find_parent(parent[x]);
        return parent[x];
    }
    void merge_p(int a,int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        if( a != b)
            parent[a] = b;
    }
    int A[301],cnt[301];
    vi pos[301];
    char S[301];
    int main()
    {
        int n;
        scan(n);
        lp(i,1,n+1)
            scan(A[i]);
        lp(i,1,n+1)
        {
            parent[i] = i;
            cnt[i] = 0;
        }
        lp(i,1,n+1)
        {
            scanf("%s",S);
            lp(j,0,n)
            {
                if( S[j] == '1')
                    merge_p(i,j+1);
            }
        }
        lp(i,1,n+1)
            pos[find_parent(i)].pb(A[i]);
        lp(i,1,n+1)
            sort(pos[i].begin(),pos[i].end());

        lp(i,1,n+1)
        {
            int g = find_parent(i);
            printf("%d ",pos[g][cnt[g]++]);
        }
        return 0;
    }
