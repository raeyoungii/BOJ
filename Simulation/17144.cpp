#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int ccw[4] = {0, 3, 2, 1};
int cw[4] = {0, 1, 2, 3};
int r, c, t;
int ac_y1 = -1, ac_x1 = -1, ac_y2 = -1, ac_x2 = -1;
int matrix[50][50];
int matrix_tmp[50][50];

void dust() {
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            matrix_tmp[y][x] = matrix[y][x];
        }
    }
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (matrix[y][x] <= 0) continue;
            int dust_value = matrix_tmp[y][x] / 5;
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (0 <= ny && ny < r && 0 <= nx && nx < c) {
                    if (matrix[ny][nx] != -1) {
                        matrix[ny][nx] += dust_value;
                        matrix[y][x] -= dust_value;
                    }
                }
            }
        }
    }
}

void wind() {
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            matrix_tmp[y][x] = matrix[y][x];
        }
    }
    // 위쪽 바람
    int y = ac_y1;
    int x = ac_x1 + 1;
    matrix[y][x] = 0;
    for (int k = 0; k < 4; k++) {
        while (true) {
            int ny = y + dy[ccw[k]];
            int nx = x + dx[ccw[k]];
            if (ny == ac_y1 && nx == ac_x1) break;
            if (!(0 <= ny && ny < r && 0 <= nx && nx < c)) break;
            matrix[ny][nx] = matrix_tmp[y][x];
            y = ny;
            x = nx;
        }
    }
    // 아래쪽 바람
    y = ac_y2;
    x = ac_x2 + 1;
    matrix[y][x] = 0;
    for (int k = 0; k < 4; k++) {
        while (true) {
            int ny = y + dy[cw[k]];
            int nx = x + dx[cw[k]];
            if (ny == ac_y2 && nx == ac_x2) break;
            if (!(0 <= ny && ny < r && 0 <= nx && nx < c)) break;
            matrix[ny][nx] = matrix_tmp[y][x];
            y = ny;
            x = nx;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1) {
                if (ac_y1 == -1) {
                    ac_y1 = i;
                    ac_x1 = j;
                } else {
                    ac_y2 = i;
                    ac_x2 = j;
                }
            }
        }
    }
    while (t--){
        dust();
        wind();
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != -1) ans += matrix[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
