#include <bits/stdc++.h>
using namespace std;
void solve(){
     int n, m;
    cin >> n >> m;

    vector<bool> no(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        no[a] = 1;
        no[b] = 1;
    }

    int center = -1;
    for (int i = 1; i <= n; ++i) {
        if (!no[i]) { center = i; break; }
    }
    cout << n - 1 << '\n';
    for (int i = 1; i <= n; ++i) {
        if (i != center)
        cout << center << ' ' << i << '\n';
    }
}
int main() {
    solve();
}