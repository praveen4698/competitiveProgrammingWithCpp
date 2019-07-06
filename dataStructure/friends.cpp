#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 2e3+10;
    string G[lim];
    int dis[lim];
    bool vis[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            cin>>G[i];
        memset(dis,0,sizeof(dis));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;++i)
        {
            if( vis[i] == false)
            {
                queue<int> Q;
                Q.push(i);
               // vis[i] = true;
                dis[i] = 0;
                while(!Q.empty())
                {
                    int f = Q.front();
                    Q.pop();
                    if(vis[f] == true)
                        continue;
                    vis[f] = true;
                    //cout<<"yu";
                    for(int c=0;c<n;++c)
                    {
                        if( G[f][c] == '1')
                        {
                            Q.push(c);
                            dis[c] = 1+dis[f];
                           // printf("%d",dis[c]);
                        }
                    }
                }
            }
        }
        map<int,int> M;
        for(int i=0;i<n;++i)
        {
            M[dis[i]]++;
        }
        int ans = M[0]*M[2];
        ans+=(M[1]*(M[1]-1));
        cout<<ans;
        return 0;
    }
