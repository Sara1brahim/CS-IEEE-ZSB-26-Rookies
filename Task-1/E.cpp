#include<bits/stdc++.h>
using namespace std;

const int N = 150002;
vector<int> adj[N];
bool vis[N];

vector<int> comp; 
void dfs(int p) {
    vis[p] = true;
    comp.push_back(p);
    for (int node : adj[p]) {
        if (!vis[node])
            dfs(node);
    }
}

void solve(){
   int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comp.clear();
            dfs(i);

            for (auto node : comp) {
                int deg = adj[node].size();
                int need = comp.size() - 1;
                if (deg != need) {
                    cout << "NO\n";
                    return ;
                }
            }
        }
    }

    cout << "YES\n";
}

int main() {
    solve();
}