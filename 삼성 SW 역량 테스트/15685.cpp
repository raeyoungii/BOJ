#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int matrix[101][101];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int cnt = 0;
    while(n--) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        vector<int> v;
        v.push_back(d);
        for (int i = 1; i <= g; i++) {
            for (int j = (int) v.size() - 1; j >= 0 ; j--) {
                v.push_back((v[j] + 1) % 4);
            }
        }
        matrix[y][x] = 1;
        for (int i = 0; i < v.size(); i++) {
            y += dy[v[i]];
            x += dx[v[i]];
            matrix[y][x] = 1;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matrix[i][j] == 1 && matrix[i + 1][j] == 1 &&
                matrix[i][j + 1] == 1 && matrix[i + 1][j + 1] == 1) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
