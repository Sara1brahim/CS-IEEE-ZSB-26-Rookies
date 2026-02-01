#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
bool vis[10001];

void dfs(int p) {
    vis[p] = true;
    for (auto node : adj[p]) {
        if (!vis[node]) dfs(node);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    if (m != n - 1) {
        cout << "NO";
        return;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
}
int main() {
    solve();
}