#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


bool check(int x, int y, int n, int m) {
    if( x >= 0 && y >= 0 && x < n && y < m)
        return true;

    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> G;
    vector<vector<pair<int, int> >>  prev(n, vector<pair<int,int> > (m, {-1, -1}));
    vector<vector<int> > dist(n, vector<int> (m, INT_MAX));

    for(int i=0;i<n;++i) {
        string a;
        cin>>a;
        G.push_back(a);
    }

    pair<int,int> start;
    pair<int, int> end;
    for(int i=0;i<n; ++i) {
        for(int j=0;j<m;++j) {
            if( G[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            if( G[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }
    int X[] = {1, -1, 0, 0};
    int Y[] = {0, 0, -1, 1};
    queue<pair<int, int> > Q;
    dist[start.first][start.second] = 0;
    prev[start.first][start.second] = {-1, -1};
    Q.push({start.first, start.second});
    while(!Q.empty()) {

        pair<int, int> t = Q.front();
        Q.pop();
        int x = t.first;
        int y = t.second;
        int distance = dist[x][y];
        // cout<<x<<y<<endl;
        for(int i=0;i<4;++i) {
            int child_x = x + X[i];
            int child_y = y + Y[i];
            if( check(child_x, child_y, n , m)&& (G[child_x][child_y] == '.' or G[child_x][child_y] == 'B') && dist[child_x][child_y] > distance + 1) {
                prev[child_x][child_y] = {x, y};
                dist[child_x][child_y] =  distance + 1;
                Q.push({child_x, child_y});
            }

        }
    }

    if( dist[end.first][end.second] < INT_MAX) {
        cout<<"YES"<<endl;
        cout<<dist[end.first][end.second]<<endl;
        vector<char> path;

        int x = end.first;
        int y = end.second;
        int count = dist[end.first][end.second];
        while(count--) {

            if( prev[x][y].first == x-1) {
                path.push_back('D');
            }
            else if( prev[x][y].first == x+1) {
                path.push_back('U');
            }
            else if( prev[x][y].second == y-1) {
                path.push_back('R');
            }
            else {
                path.push_back('L');
            }
            int xx = prev[x][y].first;
            int yy = prev[x][y].second;
            x = xx;
            y = yy;
        }
        reverse(path.begin(), path.end());
        for(int i=0;i<int(path.size()); ++i) {
            cout<<path[i];
        }
        cout<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }


    return 0;
}
