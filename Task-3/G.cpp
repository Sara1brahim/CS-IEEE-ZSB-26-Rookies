#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 3001;

int dp[N][N];
string s, t;

signed main() {
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int i = 0, j = 0;
    string ans = "";

    while (i < n && j < m) {
        if (s[i] == t[j]) {
            ans += s[i];
            i++; j++;
        } else if (dp[i+1][j] >= dp[i][j+1]) {
            i++;
        } else {
            j++;
        }
    }

    cout << ans;
    return 0;
}
