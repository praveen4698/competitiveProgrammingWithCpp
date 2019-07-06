#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    string S[50000];
    vector<bool> visited[50000];
    int R,C;

    int DFS(int i,int j)
    {
        //printf("yo\n");
        if( S[i][j] == '#' || visited[i][j] == true)
            return 0;
        int ans = 1;
        visited[i][j] = true;
        if( i > 0 ) ans+=DFS(i-1,j);
        if( i < R-1) ans+=DFS(i+1,j);
        if( j > 0 ) ans+=DFS(i,j-1);
        if( j < C-1) ans+=DFS(i,j+1);
        //printf("yp\n");
        return ans;

    }
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            scan2(R,C);
            lp(i,0,R)
                visited[i].clear();
            lp(i,0,R)
                lp(j,0,C)
                    visited[i].pb(false);

            lp(i,0,R)
                cin>>S[i];

            long double ans1 = 1.00;

            int cont = DFS(0,0);
            //printf("%d\n",cont);
            lp(i,0,R)
                lp(j,0,C)
                {
                    if( i == 0 && j == 0) continue;
                    int temp = DFS(i,j);
                    if( temp == 0) continue;

                  //  printf("%d \n",temp);
                    ans1 = ans1 + (long double)(temp)/(long double)(temp + cont);

                }
            cout<<setprecision(10) <<ans1;
            printf("\n");
        }
        return 0;
    }
