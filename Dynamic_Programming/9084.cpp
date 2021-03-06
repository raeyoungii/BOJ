#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int c[21];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int m; cin >> m;
    int dp[10001] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = c[i]; j <= m; j++) {
            dp[j] += dp[j - c[i]];
        }
    }
    cout << dp[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
