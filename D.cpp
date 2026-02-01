#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MX = 2e5 + 5;
int n, m, k;
priority_queue<ll> bes[MX];
vector<pair<int,int>> adj[MX];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    bes[1].push(0);
    pq.push({0, 1});

    while(!pq.empty()){
        auto [cost, u] = pq.top(); pq.pop();
        if(cost > bes[u].top()) continue;

        for(auto &e : adj[u]){
            int v = e.first;
            ll newCost = cost + e.second;

            if(bes[v].size() < k){
                bes[v].push(newCost);
                pq.push({newCost, v});
            } else if(newCost < bes[v].top()){
                bes[v].pop();
                bes[v].push(newCost);
                pq.push({newCost, v});
            }
        }
    }

    vector<ll> ans;
    while(!bes[n].empty()){
        ans.push_back(bes[n].top());
        bes[n].pop();
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < k; i++)
        cout << ans[i] << " ";
}