#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
ll mod = 1e9+7;
const int N = 1001;
int n;
int dp[N][N];
vector<vector<char>> v;
bool valid (int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n || v[x][y] =='*')
        return 0;
    return 1;
}
int go (int i, int j){

if(!valid(i,j))return 0;
    if (i == n-1 && j == n-1) return 1;
int ret = dp[i][j];
if(~ret)return ret;
    int ch1 = go(i+1, j);
    int ch2 = go(i, j+1);
    return dp[i][j]=(ch1 + ch2)%mod;
}

signed main() {
    cin >> n;
    v.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> v[i][j];
    memset(dp,-1,sizeof(dp));
    cout << go(0,0);
    return 0;
}