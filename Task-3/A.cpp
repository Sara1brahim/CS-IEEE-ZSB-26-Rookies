#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, W;
    cin >> n >> W;

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;

        for (int j = W; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[W] << endl;
    return 0;
}