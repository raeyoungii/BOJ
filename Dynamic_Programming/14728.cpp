#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k[101], s[101];
int dp[101][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - k[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - k[i]] + s[i]);
        }
    }
    cout << dp[n][t] << "\n";
    return 0;
}
