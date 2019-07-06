#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

typedef long long ll;
const int INF = 1e9;

const int N = 5e5;
const int M = 1e9+7;

vector<int> g[N];
int color[N];
int level[N];
int cnt[N];

vector<int> dp[N];
int result[N];

void dfs(int v) {
    int s = level[v] > 0 && level[v] < cnt[color[v]] ? dp[color[v]][level[v]-1] : 0;
    //cout<<"s="<<s<<endl;
    for (auto u : g[v]) {
        dfs(u);
    }
    if (level[v] >= cnt[color[v]]) return;
    if (level[v] == 0) {
        result[v] = 1;
    } else {
        result[v] += (dp[color[v]][level[v]-1] - s + M) % M;
        result[v] %= M;
    }
    cout<<result[v]<<endl;
    dp[color[v]][level[v]] += result[v];
    dp[color[v]][level[v]] %= M;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            dp[i].clear();
            cnt[i] = 0;
            result[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int p;
            scanf("%d", &p);
            g[p].pb(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> color[i];
            cnt[color[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(cnt[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin >> level[i];
        }
        dfs(0);
        for (int i = 0; i < n; ++i) {
            printf("%d\n", result[i]);
        }
    }

    return 0;
}
