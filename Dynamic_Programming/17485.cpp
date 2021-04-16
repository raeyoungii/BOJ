#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;
const int dx[4] = {-1, 0, 1};

int n, m;
int A[1001][1001];
int D[1001][1001][3];

int dfs(int y, int x, int d) {
    if (y == n) return 0;
    int& ret = D[y][x][d];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < 3; i++) {
        if (i != d && 0 <= x + dx[i] && x + dx[i] < m)
            ret = min(ret, dfs(y + 1, x + dx[i], i) + A[y][x]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    memset(D, -1, sizeof(D));
    int ans = INF;
    for (int x = 0; x < m; x++) {
        for (int i = 0; i < 3; i++) {
            if (0 <= x + dx[i] && x + dx[i] < m)
                ans = min(ans, dfs(0, x, i));
        }
    }
    cout << ans << nl;
    return 0;
}
