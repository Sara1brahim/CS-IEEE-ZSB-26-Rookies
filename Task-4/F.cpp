#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int N = 1e5+100;
const long long INF = 1e18;
const int MOD = 1e9+7;

vector<pair<int,int>> adj[N];
int n, m;
int x;

void go() {
    vector<long long> distance(n+1, INF);
    vector<int> ways(n+1, 0);
    vector<int> minFlights(n+1, 1e9), maxFlights(n+1, -1);

    distance[x] = 0;
    ways[x] = 1;
    minFlights[x] = 0;
    maxFlights[x] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, x});

    while(!q.empty()) {
        int a = q.top().second;
        int d = q.top().first;
        q.pop();

        if(d > distance[a]) continue;

        for(auto u : adj[a]) {
            int b = u.first;
            int w = u.second;

            if(distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                ways[b] = ways[a];
                minFlights[b] = minFlights[a] + 1;
                maxFlights[b] = maxFlights[a] + 1;
                q.push({distance[b], b});
            } else if(distance[a] + w == distance[b]) {
                ways[b] = (ways[b] + ways[a]) % MOD;
                minFlights[b] = min(minFlights[b], minFlights[a] + 1);
                maxFlights[b] = max(maxFlights[b], maxFlights[a] + 1);
            }
        }
    }

    cout << distance[n] << " " << ways[n] << " " << minFlights[n] << " " << maxFlights[n] << "\n";
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
    }

    go();

    return 0;
}