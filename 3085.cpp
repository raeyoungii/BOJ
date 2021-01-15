#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int max_n = 0;
char matrix[51][51];

void get_max() {
    for (int i = 0; i < n; i++) {
        int cnt_h = 1;
        int cnt_v = 1;
        for (int j = 0; j < n; j++) {
            // 가로
            if (matrix[i][j] == matrix[i][j + 1]) cnt_h++;
            else {
                max_n = max(max_n, cnt_h);
                cnt_h = 1;
            }
            // 세로
            if (matrix[j][i] == matrix[j + 1][i]) cnt_v++;
            else {
                max_n = max(max_n, cnt_v);
                cnt_v = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 가로
            swap(matrix[i][j], matrix[i][j + 1]);
            get_max();
            swap(matrix[i][j], matrix[i][j + 1]);
            // 세로
            swap(matrix[j][i], matrix[j + 1][i]);
            get_max();
            swap(matrix[j][i], matrix[j + 1][i]);
        }
    }
    cout << max_n << "\n";
    return 0;
}
