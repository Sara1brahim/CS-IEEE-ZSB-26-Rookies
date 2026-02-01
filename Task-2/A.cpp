#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> par(n+1, -1);
    queue<int> q;
    q.push(1);
    par[1] = 0;
    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == n) break;
        for (int u : adj[v]) {
            if (par[u] == -1) {
                par[u] = v;
                q.push(u);
            }
        }
    }
    
    if (par[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> path;
    for (int v = n; v != 0; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
    return 0;
}