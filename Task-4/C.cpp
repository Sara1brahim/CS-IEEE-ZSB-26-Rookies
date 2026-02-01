#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};

int bfs(pair<int,int> start, pair<int,int> end) {
    queue<pair<int,int>> q;
    int dist[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            dist[i][j] = -1;

    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(x == end.first && y == end.second)
            return dist[x][y];

        for(int k=0;k<8;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

int main(){
    string a,b;
    while(cin >> a >> b){
        pair<int,int> start = {a[1]-'1', a[0]-'a'};
        pair<int,int> end = {b[1]-'1', b[0]-'a'};
        int moves = bfs(start,end);
        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves.\n";
    }
}