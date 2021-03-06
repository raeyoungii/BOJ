#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w[101], v[101];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        int weight = w[i], val = v[i];
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - weight >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + val);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
