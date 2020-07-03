#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
int graph[1001][1001];
string s[1001];

bool check(int i,int j, int n,int m) {
    if ( i >= 0 and i <= n-1 and j>=0 and j <= m-1)
        return true;
    return false;
}

int BFS(int n, int m) {
    int ans = 0;
    memset(graph, 0, sizeof(graph));

    int count = 1;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(graph[i][j] > 0 or s[i][j] == '#')
                continue;
            queue<pair<int,int> > Q;
            graph[i][j] = count;
            count++;
            Q.push(make_pair(i,j));
            while(!Q.empty()) {
                pair<int,int> t = Q.front();
                Q.pop();
                int x = t.first;
                int y = t.second;
                // printf("%d %d\n", x,y);
                int value = graph[x][y];
                if(check(x-1,y, n, m) && graph[x-1][y] == 0 && s[x-1][y] == '.' ) {
                    graph[x-1][y] = value;
                    Q.push(make_pair(x-1, y));
                }
                if(check(x+1,y, n, m) && graph[x+1][y] == 0 && s[x+1][y] == '.' ) {
                    graph[x+1][y] = value;
                    Q.push(make_pair(x+1, y));
                }
                if(check(x,y-1, n, m) && graph[x][y-1] == 0 && s[x][y-1] == '.' ) {
                    graph[x][y-1] = value;
                    Q.push(make_pair(x, y-1));
                }
                if(check(x,y+1, n, m) && graph[x][y+1] == 0 && s[x][y+1] == '.' ) {
                    graph[x][y+1] = value;
                    Q.push(make_pair(x, y+1));
                }
            }

        }
    }
    return count - 1;
}
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i) {
        cin>>s[i];
    }

    printf("%d\n", BFS(n, m));
}