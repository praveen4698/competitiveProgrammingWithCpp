#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int n,m;
    char R[101],C[101];
    bool v[51][51];
    bool BFS(int x,int y)
    {
        memset(v,false,sizeof(v));
        queue<pair<int,int> > Q;
        Q.push(make_pair(x,y));

        while(!Q.empty())
        {
            pair<int ,int> t = Q.front();
            int x = t.first;
            int y = t.second;
            Q.pop();
         //   printf("x = %d y =  %d\n",x,y);
            if(v[x][y] == true)
                continue;
            v[x][y] = true;
            if(R[x] == '>' && (y+1 < m))
             {
                 Q.push(make_pair(x,y+1));
              //   printf("=========%d ========%d\n",x,y);
             }
            else if( R[x] == '<' && y-1 >= 0)
                Q.push(make_pair(x,y-1));

            if(C[y] == '^'  &&  x-1 >= 0)
             {
                 Q.push(make_pair(x-1,y));
               //  printf("=========%d ========%d\n",x-1,y);
             }
            else if(C[y] == 'v' && x+1 < n)
                Q.push(make_pair(x+1,y));
        }

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(v[i][j] == false)
                    return false;

        return true;
    }
    int main()
    {
        scanf("%d %d",&n,&m);
        scanf("%s",R);
        scanf("%s",C);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(BFS(i,j) == false)
                {
                  //  printf("%d %d\n",i,j);
                    printf("NO\n");
                    return 0;
                }
            }
        }
        printf("YES\n");
        return 0;
    }

