#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int c[21];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int m; cin >> m;
    int dp[21][10001];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (j == c[i] ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = c[i] + 1; j <= m; j++) {
            int cnt = 0;
            for (int k = 1; k <= i; k++) {
                if (j - c[i] > 0) cnt += dp[k][j - c[i]];
            }
            dp[i][j] = cnt;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][m];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
