#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

const int N = 105;
const int MAXSUM = 100000;

int n;
int a[N];
bool can[MAXSUM + 1];
bool vis[N][MAXSUM + 1];

void go(int i, int sum) {
    if (vis[i][sum]) return;
    vis[i][sum] = true;

    if (i == n) {
        if (sum > 0)
            can[sum] = true;
        return;
    }

    go(i + 1, sum);

    if (sum + a[i] <= MAXSUM)
        go(i + 1, sum + a[i]);
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    go(0, 0);

    vector<int> ans;
    for (int i = 1; i <= MAXSUM; i++)
        if (can[i]) ans.push_back(i);

    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
}