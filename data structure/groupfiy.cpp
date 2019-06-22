#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int parent[201];
    int par(int x)
    {
        if( parent[x] == -1)
            return x;
        return parent[x] = par(parent[x]);
    }
    int main()
    {
        int n;
        scanf("%d",&n);

        map<string,int> G;
        for(int i=1;i<201;++i)
            parent[i] = -1;
        int cont = 0;
        for(int i=0;i<n;++i)
        {
            string a,b,c;
            cin>>a>>b>>c;
            if(G[a] == 0)
            {
                cont++;
                G[a] = cont;
            }
            if(G[c] == 0)
            {
                cont++;
                G[c] = cont;
            }
            int fx = par(G[a]);
            int fy = par(G[c]);
            parent[fx] = fy;
        }
        vector<string> G[201];

    }
