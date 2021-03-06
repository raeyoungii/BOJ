#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m[101], c[101];
int dp[101][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> m[i];
    for (int i = 1; i <= N; i++) cin >> c[i];
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - c[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);
            if (dp[i][j] >= M) ans = min(ans, j);
        }
    }
    cout << ans << "\n";

    return 0;
}
