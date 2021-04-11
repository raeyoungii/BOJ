#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int matrix[20][20];

int chk(int y, int x) {
    for (int c = 1; c <= 2; c++) {
        int ny = y;
        int cnt = 0;
        while (matrix[ny][x] == c) {
            cnt++; ny++;
            if (ny > 19) break;
        }
        if (cnt == 5) {
            if (!(ny - 6 >= 1 && matrix[ny - 6][x] == c)) return c;
        }
        int nx = x;
        cnt = 0;
        while (matrix[y][nx] == c) {
            cnt++; nx++;
            if (nx > 19) break;
        }
        if (cnt == 5) {
            if (!(nx - 6 >= 1 && matrix[y][nx - 6] == c)) return c;
        }
        ny = y, nx = x;
        cnt = 0;
        while (matrix[ny][nx] == c) {
            cnt++; ny++; nx++;
            if (ny > 19 || nx > 19) break;
        }
        if (cnt == 5) {
            if (!(ny - 6 >= 1 && nx - 6 >= 1 && matrix[ny - 6][nx - 6] == c)) return c;
        }
        ny = y, nx = x;
        cnt = 0;
        while (matrix[ny][nx] == c) {
            cnt++; ny--; nx++;
            if (ny < 1 || nx > 19) break;
        }
        if (cnt == 5) {
            if (!(ny + 6 <= 19 && nx - 6 >= 1 && matrix[ny + 6][nx - 6] == c)) return c;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            int ans = chk(i, j);
            if (ans) {
                cout << ans << "\n" << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << "0\n";
    return 0;
}
