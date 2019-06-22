#include<bits/stdc++.h>
using namespace std;

const int lim = 1e5 + 10;
vector<int> G[lim];
int ind = 1,n;
int pos[lim],num[lim],bit[lim],w[lim];

    void DFS(int u)
    {

        num[u] = 1;
        pos[u] = ind;
        ind++;
        for(int i = 0;i<G[u].size();++i)
        {
            int v = G[u][i];
            if(num[v] == 0)
            {
                DFS(v);
                num[u]+=num[v];
            }
        }
    }
    void update(int pos,int value)
    {
        while(pos<=n)
        {
            bit[pos]+=value;
            pos+=((pos)&(-pos));
        }
    }
    int query(int pos)
    {
        int sum = 0;
        while(pos>0)
        {
            sum+=bit[pos];
            pos-=(pos)&(-pos);
        }
        return sum;
    }
    int main()
    {
        int m;
        scanf("%d %d",&n,&m);

        for(int i = 0;i<n-1;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);

        }
        for(int i =1;i<n+1;++i)
            scanf("%d",&w[i]);
        DFS(1);
        for(int i = 1;i<=n;++i)
        {
            if(w[i] == 0)
                update(pos[i],1);
            else
                update(pos[i],0);
        }

        while(m--)
        {
            char a;
            cin>>a;
            if( a == 'Q')
            {
                int po;
                cin>>po;
                printf("%d\n",query(pos[po]+num[po]-1) - query(pos[po] -1));
            }
            else
            {
                int b,c;
                scanf("%d %d",&b,&c);
                if(c == 0)
                    continue;
                if( w[b]  == 0)
                {

                    update(pos[b],-1);
                    w[b]+=c;
                }
                else if( w[b]+ c == 0)
                {
                    update(pos[b],1);
                    w[b]+=c;
                }
                else
                    w[b]+=c;

            }
        }
        return 0;
    }


