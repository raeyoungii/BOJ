#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n, l, r;
bool flag;
int ans = 0;
int matrix[50][50];
bool vst[50][50];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;
    int sum = 0, cnt = 0;
    q.emplace(i, j);
    tmp.emplace(i, j);
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        vst[y][x] = true;
        sum += matrix[y][x];
        cnt++;
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 <= ny && ny < n && 0 <= nx && nx < n && !vst[ny][nx]) {
                int diff = abs(matrix[ny][nx] - matrix[y][x]);
                if (l <= diff && diff <= r) {
                    flag = true;
                    vst[ny][nx] = true;
                    q.emplace(ny, nx);
                    tmp.emplace(ny, nx);
                }
            }
        }
    }
    int new_pop = sum / cnt;
    while (!tmp.empty()) {
        int y = tmp.front().first;
        int x = tmp.front().second;
        tmp.pop();
        matrix[y][x] = new_pop;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    while (true) {
        memset(vst, false, sizeof(vst));
        flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vst[i][j]) {
                    bfs(i, j);
                }
            }
        }
        if (!flag) break;
        else ans++;
    }
    cout << ans << "\n";
    return 0;
}
