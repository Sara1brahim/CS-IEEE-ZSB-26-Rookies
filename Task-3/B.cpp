#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;

int n, k;
vector<int> h;
vector<ll> dp;

ll solve(int i) {
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    ll ans = inf;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            ans = min(ans,
                      solve(i - j) + abs(h[i] - h[i - j]));
        }
    }

    return dp[i] = ans;
}

int main() {
    cin >> n >> k;

    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    dp.assign(n, -1);

    cout << solve(n - 1) << endl;
    return 0;
}