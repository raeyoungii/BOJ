#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int matrix[50][50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int r, c, d; cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int cnt = 0, ans = 0;
    while (true) {
        if (matrix[r][c] == 0) {
            matrix[r][c] = -1;
            ans++;
        }
        if (cnt < 4) {
            int nr = r + dy[(d + 3) % 4];
            int nc = c + dx[(d + 3) % 4];
            if (matrix[nr][nc] == 0) {
                r = nr, c = nc;
                cnt = 0;
            } else cnt++;
            d = (d + 3) % 4;
        } else {
            int nr = r + dy[(d + 2) % 4];
            int nc = c + dx[(d + 2) % 4];
            if (matrix[nr][nc] != 1) {
                r = nr, c = nc;
                cnt = 0;
            } else break;
        }
    }
    cout << ans << "\n";
    return 0;
}
