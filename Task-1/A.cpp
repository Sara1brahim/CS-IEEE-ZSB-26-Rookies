#include <bits/stdc++.h>
using namespace std;
void solve (){
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<int> ans (n+1, 0);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    for (int i = 1; i <=n; i++)
        cout << ans[i] <<'\n';
}
int main() {
    solve();
}