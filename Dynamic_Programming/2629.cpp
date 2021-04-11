#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int weight[31], marble[8];
int dp[31][40001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> weight[i];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    int m; cin >> m;
    for (int i = 1; i <= m; i++) cin >> marble[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 40000; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][abs(j - weight[i])]);
            if (j + weight[i] <= 40000) dp[i][j] = max(dp[i][j], dp[i - 1][j + weight[i]]);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << (dp[n][marble[i]] ? "Y" : "N") << " ";
    }
    return 0;
}
