#include <bits/stdc++.h>
using namespace std;
#define int  long long
void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> dist(20002, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        if (x == m) {
            cout << dist[x] << "\n";
            return ;
        }

        if (  x - 1 > 0 && dist[x - 1] == -1) {
            dist[x - 1] = dist[x] + 1;
            q.push(x - 1);
        }

        if (x * 2 <= 20000 && dist[x * 2] == -1  ) {
            dist[x * 2] = dist[x] + 1;
            q.push(x * 2);
        }
    }
}

signed main() {
    solve();
}