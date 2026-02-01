#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
const long long INF = 1e18;

int n, m;
vector<pair<int,int>> adj[MAXN];
long long dist[MAXN][2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    for(int i = 1; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][0] = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0, {1,0}});

    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int cost = top.first;
        int u = top.second.first;
        int used = top.second.second;

        if(cost > dist[u][used]) continue;

        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;

            if(dist[v][used] > dist[u][used] + w){
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], {v, used}});
            }

            if(used == 0){
                long long newCost = dist[u][0] + w/2;
                if(dist[v][1] > newCost){
                    dist[v][1] = newCost;
                    pq.push({newCost, {v,1}});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";
}
