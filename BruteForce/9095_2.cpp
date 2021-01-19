#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans;

void dfs(int idx, int n) {
    if (idx > n) return;
    if (idx == n) {
        ans++;
        return;
    }
    for (int i = 1; i <= 3; i++) dfs(idx + i, n);
}

void solve() {
    int n; cin >> n;
    ans = 0;
    dfs(0, n);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
