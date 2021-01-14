#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = {1, 0};
int dy[4] = {0, 1};
int matrix[101][101];
ll dp[101][101];
int n;

ll dfs(int y, int x) {
    if (y == n - 1 && x == n - 1) return 1;
    if (dp[y][x] == -1) {
        dp[y][x] = 0;
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i] * matrix[y][x];
            int nx = x + dx[i] * matrix[y][x];
            if (ny < n && nx < n) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0) << "\n";
    return 0;
}
