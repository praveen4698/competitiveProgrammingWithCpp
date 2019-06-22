#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[101][101],counti[101];
    bool visited[101][101];
    queue<pii> Q[101];
    int main()
    {
        while(1)
        {
            int n ;
            scan(n);
            if( n == 0)
                break;
            lp(i,1,n+1)
                lp(j,1,n+1)
                 {
                     A[i][j] = n;
                     visited[i][j] = false;
                 }
            cin.get();
             lp(i,1,n)
             {

                string temp;
                getline( cin , temp );
                stringstream ss( temp );
                int x , y;
                int j = 0;
                while ( ss >> x && ss >> y )
                {

                    A[ x ][ y ] = i ;
                    if( j == 0)
                    {
                        Q[i].push(mp(x,y));
                        j++;
                    }
                }
             /*   lp(j,1,n+1)
                {
                    int a,b;
                    scan(a);
                    scan(b);
                    A[a][b] = i;
                    if( j == 1)
                        Q[i].push(mp(a,b));
                    if(n == j){while(getchar()!='\n');}
                }*/
                //if(n==j+1){while(getchar()!='\n');}
               // printf("\n");
             }
            lp(i,1,n+1)
                lp(j,1,n+1)
                {
                    if( A[i][j] == n)
                    {
                        Q[n].push(mp(i,j));
                        i = n+4;
                        break;

                    }
                }

            lp(i,1,n+1)
            {
                counti[i] = 0;
                while(!Q[i].empty())
                {
                    pii t = Q[i].front();
                    int a = t.F;
                    int b = t.S;
                    Q[i].pop();
                    counti[i] = counti[i]+1;
                    visited[a][b] = true;
                    if( a + 1 <= n &&  A[a+1][b] == i && visited[a+1][b] == false)
                        Q[i].push(mp(a+1,b));
                    if( a-1 > 0 && A[a-1][b] == i && visited[a-1][b] == false)
                        Q[i].push(mp(a-1,b));
                    if( b+1 <= n && A[a][b+1] == i && visited[a][b+1] == false)
                        Q[i].push(mp(a,b+1));
                    if( b-1 > 0 && A[a][b-1] == i && visited[a][b-1] == false)
                        Q[i].push(mp(a,b-1));
                }
            }

            int flag = 0;
            lp(i,1,n+1)
            {
               lp(j,1,n+1)
               {
                   if( visited[i][j] == false)
                        flag = 1;
               }
            }
            if( flag == 1)
                printf("wrong\n");
            else
                printf("good\n");

        }
        return 0;
    }

