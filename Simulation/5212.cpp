#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

string matrix[10], matrix_50y[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> matrix[i];
        matrix_50y[i] = matrix[i];
    }
    int min_y = 10, min_x = 10, max_y = -1, max_x = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 'X') {
                int sea = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 <= ny && ny < r && 0 <= nx && nx < c) {
                        if (matrix[ny][nx] == '.') sea++;
                    }
                    else sea++;
                }
                if (sea >= 3) matrix_50y[i][j] = '.';
                else {
                    min_y = min(min_y, i);
                    min_x = min(min_x, j);
                    max_y = max(max_y, i);
                    max_x = max(max_x, j);
                }
            }
        }
    }
    for (int i = min_y; i <= max_y; i++) {
        for (int j = min_x; j <= max_x; j++) {
            cout << matrix_50y[i][j];
        }
        cout << "\n";
    }
    return 0;
}
