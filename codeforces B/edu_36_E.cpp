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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, splay_tree_tag, tree_order_statistics_node_update>
int M[1000001];
int main()
{
    ordered_set tree;
    int n;
    scan(n);
    int q;
    scan(q);
    //unordered_map<int,int> M;
   memset(M,0,sizeof(M));
    for(int i=1; i<=n; ++i)
        tree.insert(i),M[i] = 1;

    while(q--)
    {
        int a,b;
        scan2(a,b);
        if( a == 0)
        {
            if( M[b] == 0)
                continue;
            tree.erase(b);
            M[b]--;
            n--;
        }
        else
        {
            if( b > n)
                print(-1);
            else
                print(*tree.find_by_order(b-1));
        }
    }
    return 0;
}


