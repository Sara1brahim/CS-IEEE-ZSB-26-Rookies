#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int N = 1e5+100;

const long long INF = 1e18;
vector<pair<int,int>> adj[N];
int n, m;
int x;

void go() {
    vector<int> distance(n+1, INF);
    vector<int> parent(n+1, -1);   
    vector<bool> processed(n+1, false);

    distance[x] = 0;

    priority_queue<pair<int,int>> q;
    q.push({0, x});

    while(!q.empty()) {
        int a = q.top().second;
        q.pop();

        if(processed[a]) continue;
        processed[a] = true;

        for(auto u : adj[a]) {
            int b = u.first;
            int w = u.second;

            if(distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                parent[b] = a;   
                q.push({-distance[b], b});
            }
        }
    }

    if(distance[n] == INF) {
        cout << -1 << "\n";
        return;
    }

    vector<int> path;
    for(int v = n; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    for(int v : path) cout << v << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    x = 1;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});  
    }

    go();

    return 0;
}