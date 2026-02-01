#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
 
int n, m, k;
vector<vector<int>> dist;
vector<pair<int,int>> burn;
pair<int,int> ansPos;
 
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1;
}
 
void bfs() {
    queue<pair<int,int>> q;
    for(int i = 0; i < k; i++) {
        int x = burn[i].first;
        int y = burn[i].second;
        dist[x][y] = 0;
        q.push({x, y});
        ansPos = {x, y};
    }
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        ansPos = {x, y};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny)) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    cin >> k;
    burn.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> burn[i].first >> burn[i].second;
        burn[i].first--;
        burn[i].second--;
    }
    dist.assign(n, vector<int>(m, -1));
    bfs();
    cout << ansPos.first + 1 << " " << ansPos.second + 1;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}