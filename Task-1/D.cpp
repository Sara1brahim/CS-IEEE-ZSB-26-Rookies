#include<bits/stdc++.h>
using namespace std;

const int N = 501;
vector<vector<int>> adj(N);
vector<vector<int>> vis(N, vector<int>(N, false));
char g[N][N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, k;

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
    if(k){
        g[i][j] = 'X';
        k--;
    }

}
void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i,j) ) {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }
        cout<<'\n';
    }
}

int main() {
    solve();
    return 0;
}