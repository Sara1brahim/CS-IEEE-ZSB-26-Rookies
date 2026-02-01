#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<ll> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << "\n";
    return 0;
}