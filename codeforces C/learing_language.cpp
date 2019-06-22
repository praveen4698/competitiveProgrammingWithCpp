#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 101;
    int p[lim];
    map<int,int> M;
    int parent(int x)
    {
        if( p[x] == -1 || p[x] == x)
        {
            p[x] = x;
            return p[x];
        }
        p[x] = parent(p[x]);
        return p[x];
    }

    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=m;++i)
            p[i] = -1;
        int cont = 0;
        for(int i=0;i<n;++i)
        {
            int k;
            scanf("%d",&k);
            if(k == 0)
                cont++;
            else
            {
                int a,p1;
                scanf("%d",&a);
                p1 = parent(a);
                for(int j=1;j<k;++j)
                {
                    scanf("%d",&a);
                    int p2 = parent(a);
                    if( a == p2)
                        p[a] = p1;
                    else
                    {
                        p[p1] = p2;
                        p1 = p2;
                    }
                }
            }

        }
        for(int i=1;i<=m;++i)
        {
            if(p[i] != -1 )
                M[parent(i)]++;
        }
        int ans = cont;
        if(M.size() >= 1)
            ans = ans + M.size() -1;
        printf("%d",ans);
        return 0;
    }
