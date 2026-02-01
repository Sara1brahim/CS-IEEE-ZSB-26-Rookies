#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dirC[] = {'D', 'L', 'R', 'U'};

int n, m;
string grid[1005];

int distM[1005][1005];
int distA[1005][1005];

pair<int,int> parentA[1005][1005];
char moveToA[1005][1005];

pair<int,int> start;

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void bfsMonsters(queue<pair<int,int>> &q){
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny) && distM[nx][ny] == -1){
                distM[nx][ny] = distM[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

pair<int,int> bfsPlayer(){
    queue<pair<int,int>> q;
    q.push(start);
    distA[start.first][start.second] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m-1)
            return {x, y};

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(valid(nx, ny) && distA[nx][ny] == -1){
                int na = distA[x][y] + 1;
                int nm = distM[nx][ny];

                if(nm == -1 || na < nm){
                    distA[nx][ny] = na;
                    parentA[nx][ny] = {x, y};
                    moveToA[nx][ny] = dirC[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    return {-1, -1};
}

string buildPath(pair<int,int> en){
    string path;
    pair<int,int> cur = en;

    while(cur != start){
        path += moveToA[cur.first][cur.second];
        cur = parentA[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    cin >> n >> m;

    queue<pair<int,int>> qm;

    for(int i=0; i<n; i++){
        cin >> grid[i];
        for(int j=0; j<m; j++){
            distM[i][j] = -1;
            distA[i][j] = -1;

            if(grid[i][j] == 'A')
                start = {i, j};

            if(grid[i][j] == 'M'){
                qm.push({i, j});
                distM[i][j] = 0;
            }
        }
    }

    bfsMonsters(qm);

    pair<int,int> exit = bfsPlayer();

    if(exit.first == -1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string path = buildPath(exit);
    cout << path.size() << "\n";
    cout << path << "\n";
}

int main(){
    solve();
    return 0;
}