#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;


const int lim = 2e3+10;
string S[lim];
ll dp1[lim][lim];
ll dp2[lim][lim];
ll n,m;
priority_queue<pair<ll,pair<ll,ll> > > Q;
void DFS(int r,int c){

    //dp1[r][c] = 0;
    while(!Q.empty())
        Q.pop();
    Q.push({0ll,{r,c}});
    while(!Q.empty()){

        pair<ll,pair<ll,ll> > t = Q.top();
        Q.pop();
        int row = t.second.first;
        int col = t.second.second;
        int cost = (-1ll) *t.first;
        if( dp1[row][col] != 0)
            continue;
        dp1[row][col] = cost;
        if( row+1 < n && S[row+1][col] == '.'){
            Q.push({cost,{row+1,col}});
        } 
        if( row-1 >= 0 && S[row-1][col] == '.'){
            Q.push({cost,{row-1,cost}});
        }
        if( col+1 < m && S[row][col+1] == '.'){
            Q.push({cost,{row,col+1}});
        }
        if( col-1 >= 0 && S[row][col-1] == '.'){
            Q.push({-1ll*(cost+1ll),{row,col-1}});
        }
    }


}
void DFS2(int r,int c){

    //dp1[r][c] = 0;
    while(!Q.empty())
        Q.pop();
    Q.push({0ll,{r,c}});
    while(!Q.empty()){

        pair<ll,pair<ll,ll> > t = Q.top();
        Q.pop();
        int row = t.second.first;
        int col = t.second.second;
        int cost = (-1ll) *t.first;
        if( dp2[row][col] != 0)
            continue;
        dp2[row][col] = cost;
        if( row+1 < n && S[row+1][col] == '.'){
            Q.push({cost,{row+1,col}});
        } 
        if( row-1 >= 0 && S[row-1][col] == '.'){
            Q.push({cost,{row-1,cost}});
        }
        if( col+1 < m && S[row][col+1] == '.'){
            Q.push({(-1ll*(cost+1)),{row,col+1}});
        }
        if( col-1 >= 0 && S[row][col-1] == '.'){
            Q.push({cost,{row,col-1}});
        }
    }


}
int main()
{
    cin>>n>>m;
    int r,c;
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cin>>r>>c;
    r--,c--;
    int L,R;
    cin>>L>>R;
    for(int i=0;i<n;++i)
        cin>>S[i];
    DFS(r,c);
    DFS(r,c);
    int ans = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if( S[i][j] == '*')
                continue;
            if( i <= r && dp1[i][j] <= L && dp1[i][j]-(r-i) <= R){
                ans++;
                print(i);
                print(j);
                continue;
            }
            if( i > r && dp1[i][j] <= L && dp1[i][j]+(i-r) <= R){
                print(i);
                print(j);
                ans++;
                continue;
            }
            if( i <= r && dp2[i][j] <= R && dp2[i][j]+(r-i) <= L){
                print(i);
                print(j);
                ans++;
                continue;
            }
            if( i > r && dp2[i][j] <= R && dp2[i][j]-(r-i) <= L){
                print(i);
                print(j);
                ans++;
                continue;

            }
        }
    
    }
    printf("%d",ans);
    return 0;
}