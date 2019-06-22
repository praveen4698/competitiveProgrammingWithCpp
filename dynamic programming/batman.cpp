#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int cost[21][21],power[21][21],inicost[21];
    int n,m;
    struct comp
    {
        bool operator() (const pair<pair<int,int>,float>& lhs, const pair<pair<int,int>,float> & rhs) const
            {return lhs.second>rhs.second;}
    };
    int solve(int mask,int k)
    {
        //printf("\n\n\n\n");
        vector<pair<pair<int,int>,float> > temp;
        for(int i=0;i<n;++i)
        {
            if( mask&(1<<i))
            {
                for(int j=0;j<m;++j)
                {
                    if(cost[i][j] == 0)
                        continue;
                    temp.push_back(make_pair(make_pair(cost[i][j],power[i][j]),(float)((float)(power[i][j])/cost[i][j])));
                }

            }
        }
        sort(temp.begin(),temp.end(),comp());
        vector<pair< pair< int,int > , float > >::iterator it;
        int cont = 0;
        for(it = temp.begin();it != temp.end();++it)
        {
           // printf("cost = %d power = %d ratio = %f\n",(*it).first.first,(*it).first.second,(*it).second);
            int t = k/(*it).first.first  ;
            cont+=(t*(*it).first.second);
            k = k%((*it).first.first);
        }
        return cont;
        return 0;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int k;
            scanf("%d %d %d",&n,&m,&k);
            for(int i=0;i<n;++i)
                scanf("%d",&inicost[i]);
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    scanf("%d",&cost[i][j]);
                }
            }
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    scanf("%d",&power[i][j]);
                }
            }
            long long int ans = 0;
            int nn = (1<<n);
            for(int i=1;i<nn;++i)
            {
                int temp = 0;
                for(int j=0;j<n;++j)
                {
                    if(i&(1<<j))
                        temp+=inicost[j];
                }
                ans = max(ans,1LL*solve(i,k-temp));
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
