#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int matrix[501][501];
int dp[501][501];
int m, n;

int dfs(int y, int x) {
    if (y == 0 && x == 0) return 1;
    if (dp[y][x] == -1) {
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && matrix[ny][nx] > matrix[y][x]) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(m - 1, n - 1) << "\n";
    return 0;
}
