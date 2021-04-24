#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, M;
int mx;
int board[8][8];
int tmpBoard[8][8];

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmpBoard[i][j] == 2)
                q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (tmpBoard[ny][nx] == 0) {
                    tmpBoard[ny][nx] = 2;
                    q.emplace(ny, nx);
                }
            }
        }
    }
}

int countSafe() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmpBoard[i][j] == 0) ret++;
        }
    }
    return ret;
}
void copyBoard(int a[][8], int b[][8]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}
int dfs(int k, int start) {
    if (k == 3) {
        copyBoard(tmpBoard, board);
        bfs();
        return countSafe();
    }
    int ret = 0;
    for (int i = start; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0) continue;
            board[i][j] = 1;
            ret = max(ret, dfs(k + 1, i));
            board[i][j] = 0;
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
    cout << dfs(0, 0) << nl;
    return 0;
}
