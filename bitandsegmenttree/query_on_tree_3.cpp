#include<bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6+10;
   vector<int> adj[lim];
   int chainHead[lim],chainInd[lim],subsize[lim],posInBase[lim],baseArray[lim];
   set<int> tree[lim];
   int parent[lim];
   int color[lim];
   int chainNo=0,ptr=0;
    void HLD(int curNode, int prev)
    {
        if(chainHead[chainNo] == -1)
        {
            chainHead[chainNo] = curNode;
        }
        chainInd[curNode] = chainNo;
        posInBase[curNode] = ptr;
        baseArray[ptr++] = curNode;

        int sc = -1;

        for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
            {
                sc = adj[curNode][i];
            }
        }

        if(sc != -1)
            HLD(sc, curNode);

        for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc != adj[curNode][i])
            {
                chainNo++;
                HLD(adj[curNode][i], curNode);
            }
        }
        return ;
    }


    void DFS1(int cur, int prev)
    {
        subsize[cur] = 1;
        for(int i=0; i<adj[cur].size(); i++)
            if(adj[cur][i] != prev)
            {
                parent[adj[cur][i]] = cur;
                DFS1(adj[cur][i], cur);
                subsize[cur] += subsize[adj[cur][i]];
            }
    }
    inline int query(int u)
    {
        int ans = -1;
        while(u != -1)
        {
            if( !tree[chainInd[u]].empty() && *tree[chainInd[u]].begin() <= posInBase[u])
                ans = baseArray[*tree[chainInd[u]].begin()] +1;

            u = parent[chainHead[chainInd[u]]];
        }
        return ans;
    }

    int main()
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        parent[0] = -1;
        DFS1(0,-1);
        HLD(0,-1);
        for(int i=0;i<n;++i)
            color[i] = 0;
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if( a== 0)
            {
                b--;
                color[b] = 1^color[b];
                if( color[b] == 1)
                    tree[chainInd[b]].insert(posInBase[b]);
                else
                    tree[chainInd[b]].erase(posInBase[b]);

            }
            else
                printf("%d\n",query(b-1));
        }
    }
