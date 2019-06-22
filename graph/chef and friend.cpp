#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int A[1001][1001];
    int color[1001];
    bool coloring(int n ,int start)
    {
        queue<int> Q;
        Q.push(start);
        color[start] = 0;
        while(!Q.empty())
        {
             int u = Q.front();
             Q.pop();
             for(int v = 1;v<=n;++v)
             {
                 if( u != v)
                 {
                     if( A[u][v] == 1 && color[v] == -1)
                     {
                         Q.push(v);
                         color[v] = 1 - color[u];
                     }
                     else if( A[u][v] == 1 && color[v] == color[u])
                     {
                         return false;
                     }
                 }
             }

        }
        return true;
    }


	int main()
	{
	    int n;

	    int Z;
	    cin>>Z;
	    while(Z--)
        {
            int m;
            int i,j;
            cin>>n>>m;
            loop(i,0,n+1)
            {
                loop(j,0,n+1)
                {
                    A[i][j] = 1;
                }
                color[i] = -1;
            }
            loop(i,0,m)
            {
                int a,b;
                cin>>a>>b;
                A[a][b] = 0;
                A[b][a] = 0;
            }
            bool flag = true;
            loop(i,1,n+1)
            {
                if( color[i] == -1)
                {
                    flag  = coloring(n,i);
                }
                if( flag == false)
                {
                    break;
                }
            }

            if(flag == true )
            {
                cout<<"YES";
            }
            else
            {
                cout<<"NO";
            }
            printf("\n");
        }

		return 0;
	}
