#include <bits/stdc++.h>
using namespace std;
#define int  long long
const int N = 100002;
vector<vector<int>> adj(N+1);
vector<int> color(N+1, -1);
int cnt0 = 0, cnt1 = 0;
void bfs(int x){
    queue<int> q;
    color[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (color[u] == 0) ++cnt0; 
        else ++cnt1;
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
        }
    }
}

void solve (){
    int n;
    cin >> n;
    color.resize(n+1);
    adj.resize(n+1);
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    
    int total = cnt0 * cnt1;
    int exist= n - 1;
    int ans = total - exist;
    cout << ans << '\n';
}
signed main() {
   
    solve();
    return 0;
}