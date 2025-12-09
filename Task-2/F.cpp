#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg, ans;

int main(){
    cin >> n >> m;
    adj.assign(n+1, {});
    indeg.assign(n+1, 0);

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for(int u : adj[v]){
            indeg[u]--;
            if(indeg[u] == 0)
                q.push(u);
        }
    }

    if((int)ans.size() != n){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int x : ans) cout << x << " ";
}
C++
