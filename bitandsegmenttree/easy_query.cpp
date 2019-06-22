#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim  = 1e5+10;
map<pair<int,int> ,int>  M;
int col[lim];
vector<pair<int,int> >G[lim];
bool DFS(int ver,int  color,int par =-1)
{
    if( col[ver] == -1)
        col[ver] = color;
    else if( col[ver] != color)
        return false;
    else
        return true;
    for(auto a:G[ver])
    {
        if( a.first == par && a.second == color)
            continue;
        if( a.second != color)
            if(DFS(a.first,1-color,ver) == false)
                return false;
        if( a.second == color)
            if( !DFS(a.first,color,ver))
                return false;
    }
    return true;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;++i)
            G[i].clear();
        int flag = 0;
        M.clear();
        while(q--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
            if( a == b && c != 0)
                flag = 1;

            if( M.find({a,b}) != M.end())
            {
                if( M[make_pair(a,b)] != c)
                    flag = 1;
            }
            else
            {
                M.insert(make_pair(make_pair(a,b),c));
                M.insert(make_pair(make_pair(b,a),c));
            }
        }
        if( flag == 1)
            cout<<"no"<<endl;
        else
        {
            for(int i=1;i<=n;++i)
                col[i] = -1;
            flag = 0;
            for(int i=1;i<=n;++i)
            {
                if(col[i] == -1 && DFS(i,0) == false)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                cout<<"no"<<endl;
            else
                cout<<"yes"<<endl;
        }
    }
    return 0;
}
