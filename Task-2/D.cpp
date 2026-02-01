#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};
 
int n, m;
string grid[1005];
int dist[1005][1005];
pair<int, int> parent[1005][1005];
char moveTo[1005][1005];

pair<int,int> start, endd;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfs(pair<int,int> st) {
    queue<pair<int, int>> q;
    q.push(st);
    dist[st.first][st.second] = 0;
 
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                moveTo[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }
}
string buildPath(pair<int,int> st, pair<int,int> en) {
    string path;
    pair<int, int> cur = en;
    while (cur != st) {
        path += moveTo[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());
    return path;
}
void solve(){
    cin >> n >> m;
 
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            dist[i][j] = -1;
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') endd = {i, j};
        }
    }
 
    bfs(start);
 
    if (dist[endd.first][endd.second] == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[endd.first][endd.second] << '\n';
        cout << buildPath(start, endd) << '\n';
    }
}
int main() {
    solve();
    return 0;
}