#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c[201], e[201];
int matrix[1001][1001];
int dp[1001][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> e[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= n; j++) {
            // 사냥터를 옮기지 않고 계속 사냥하는 경우
            if (dp[i][j] >= c[j]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + e[j]);
            for (int k = 1; k <= n; k++) {
                if (i + matrix[j][k] <= t && dp[i][j] >= c[k]) {
                    // k번 사냥터로 옮기기로 한 경우
                    dp[i + matrix[j][k]][k] = max(dp[i + matrix[j][k]][k], dp[i][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[t][i]);
    cout << ans << "\n";
    return 0;
}
