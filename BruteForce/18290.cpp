#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;
int ans = -10001;
int matrix[11][11];
bool vst[11][11];

bool chk(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && vst[ny][nx]) {
            return false;
        }
    }
    return true;
}

void dfs(int cnt, int sum) {
    if (cnt == k) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vst[i][j] && chk(i, j)) {
                vst[i][j] = true;
                dfs(cnt + 1, sum + matrix[i][j]);
                vst[i][j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            vst[i][j] = false;
        }
    }
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}
