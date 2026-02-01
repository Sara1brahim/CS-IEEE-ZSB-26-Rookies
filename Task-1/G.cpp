#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];

void dfs(int p) {
    vis[p] = true;
    for (auto node : adj[p]) {
        if (!vis[node]) dfs(node);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> components;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            components.push_back(i);
            dfs(i);

        }
    }
    cout << components.size() - 1 <<'\n';
    for (int i = 0; i < components.size()-1; i++)
        cout <<components[i] <<" "<<components[i+1] << '\n'; 

}
int main() {
    solve();
}