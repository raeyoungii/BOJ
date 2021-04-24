#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, M;
int board[500][500];
bool vst[500][500];


int T(int y, int x) {
    int sum = board[y][x];
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (0 <= ny && ny < N && 0 <= nx && nx < M) {
            sum += board[ny][nx];
        }
    }
    int ret = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (0 <= ny && ny < N && 0 <= nx && nx < M) {
            ret = max(ret, sum - board[ny][nx]);
        } else {
            ret = max(ret, sum);
        }
    }
    return ret;
}

int f(int y, int x, int k) {
    if (k == 4) return board[y][x];
    int ret = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (0 <= ny && ny < N && 0 <= nx && nx < M) {
            if (vst[ny][nx]) continue;
            vst[ny][nx] = true;
            ret = max(ret, f(ny, nx, k + 1) + board[y][x]);
            vst[ny][nx] = false;
        }
    }
    return ret;
}

int searchBoard() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vst[i][j] = true;
            ret = max(ret, f(i, j, 1));
            vst[i][j] = false;
            ret = max(ret, T(i, j));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cout << searchBoard() << nl;
    return 0;
}
