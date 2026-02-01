#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

const int N = 100005;

int n;
int a[N], b[N], c[N];
int dp[N][4]; 

int go(int day, int last) {
    if (day == n) return 0;

    int &ret = dp[day][last];
    if (ret != -1) return ret;

    ret = 0;

    if (last != 0)
        ret = max(ret, a[day] + go(day + 1, 0));

    if (last != 1)
        ret = max(ret, b[day] + go(day + 1, 1));

    if (last != 2)
        ret = max(ret, c[day] + go(day + 1, 2));

    return ret;
}

signed main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, -1, sizeof(dp));

    cout << go(0, 3); 
    return 0;
}