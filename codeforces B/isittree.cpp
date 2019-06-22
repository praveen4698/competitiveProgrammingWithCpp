#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan(a,b) scanf("%d %d",&a,&b)
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

    int parent[10001];
    int is_pa(int i)
    {
        if( parent[i] == i)
            return i;
        parent[i] = is_pa(parent[i]);
        return parent[i];
    }

    int main()
    {
        int n,m;
        scan(n,m);
        int flag = 0;
        lp(i,0,n+1)
            parent[i] = i;
        lp(i,0,m)
        {
            int a,b;
            scan(a,b);
            int fa = is_pa(a);
            int fb = is_pa(b);
            if( fa == fb)
                flag = 1;
            else if( flag == 0)
            {
                parent[fa] = fb;
            }

        }
        int x = is_pa(1);
        if(flag == 1)
            printf("NO\n");
        else
        {
            int flag2 = 0;
            lp(i,1,n+1)
            {
                int temp = is_pa(i);
                if( x != temp)
                    flag2 = 1;
            }

            if( flag2 == 0)
                printf("YES\n");
            else
                printf("NO\n");

        }
        return 0;
    }
