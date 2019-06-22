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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 1e3+10;
int A[lim][lim];
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,m;
        scan2(n,m);
        queue<pair<int,int> > Q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scan(A[i][j]);
                if( A[i][j] > 0)
                {
                    A[i][j]++;
                    Q.push({i,j});
                }
            }
        }
        while(!Q.empty())
        {
            pair<int,int> temp = Q.front();
            int x = temp.first;
            int y = temp.second;
            Q.pop();
            int cost = A[x][y];
           // cout<<cost<<endl;
            if(cost <= 1)
                continue;
            if( x-1 >= 0 && A[x-1][y] >= 0)
            {
                if( A[x-1][y] < A[x][y]-1)
                {
                    Q.push({x-1,y});
                    A[x-1][y] = A[x][y]-1;
                }
            }
            if( x+1 < n && A[x+1][y] >= 0)
            {
                if( A[x+1][y] < A[x][y]-1)
                {
                    Q.push({x+1,y});
                    A[x+1][y] = A[x][y]-1;
                }
            }
            if( y-1 >= 0 && A[x][y-1] >= 0)
            {
                if( A[x][y-1] < A[x][y]-1)
                {
                    Q.push({x,y-1});
                    A[x][y-1] = A[x][y]-1;
                }
            }
            if( y+1 < m && A[x][y+1] >= 0)
            {
                if( A[x][y+1] < A[x][y]-1)
                {
                    Q.push({x,y+1});
                    A[x][y+1] = A[x][y]-1;
                }
            }

        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if( A[i][j] < 0)
                    cout<<"B";
                if( A[i][j] > 0)
                    cout<<"Y";
                if( A[i][j] == 0)
                    cout<<"N";
            }
            cout<<endl;
        }

    }
    return 0;
}


