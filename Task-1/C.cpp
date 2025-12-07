#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
vector<vector<int>> adj(N);
vector<vector<int>> vis(N, vector<int>(N, false));
char g[N][N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, ans;

bool valid(int i, int j) {
    if (g[i][j] == '#' || i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) {
        return false;
    }
    return true;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    int nx, ny;
    for (int x = 0; x < 4; x++) {
        nx = i + dx[x];
        ny = j + dy[x];
        if (valid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i,j)) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}