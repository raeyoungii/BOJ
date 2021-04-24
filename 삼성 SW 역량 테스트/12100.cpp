#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int N;
int board[20][20];

void copyBoard(int a[][20], int b[][20]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void checkSame(int dir) {
    if (dir == 0) {
        // 왼쪽
        for (int i = 0; i < N; i++) {
            int l = 0, r = 1;
            while (r < N) {
                if (board[i][r]) {
                    if (board[i][l] == board[i][r]) {
                        board[i][l] *= 2;
                        board[i][r] = 0;
                        l = r + 1;
                        r = r + 2;
                    } else {
                        l = r;
                        r = r + 1;
                    }
                } else r++;
            }
        }
    } else if (dir == 1) {
        // 오른쪽
        for (int i = 0; i < N; i++) {
            int l = N - 1, r = N - 2;
            while (r >= 0) {
                if (board[i][r]) {
                    if (board[i][l] == board[i][r]) {
                        board[i][l] *= 2;
                        board[i][r] = 0;
                        l = r - 1;
                        r = r - 2;
                    } else {
                        l = r;
                        r = r - 1;
                    }
                } else r--;
            }
        }
    } else if (dir == 2) {
        // 위
        for (int i = 0; i < N; i++) {
            int l = 0, r = 1;
            while (r < N) {
                if (board[r][i]) {
                    if (board[l][i] == board[r][i]) {
                        board[l][i] *= 2;
                        board[r][i] = 0;
                        l = r + 1;
                        r = r + 2;
                    } else {
                        l = r;
                        r = r + 1;
                    }
                } else r++;
            }
        }
    } else if (dir == 3) {
        // 아래
        for (int i = 0; i < N; i++) {
            int l = N - 1, r = N - 2;
            while (r >= 0) {
                if (board[r][i]) {
                    if (board[l][i] == board[r][i]) {
                        board[l][i] *= 2;
                        board[r][i] = 0;
                        l = r - 1;
                        r = r - 2;
                    } else {
                        l = r;
                        r = r - 1;
                    }
                } else r--;
            }
        }
    }
}

void moveBoard(int dir) {
    if (dir == 0) {
        // 왼쪽
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = 0; j < N; j++) {
                if (board[i][j]) {
                    v.push_back(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int x = 0;
            for (int& k : v) board[i][x++] = k;
        }
    } else if (dir == 1) {
        // 오른쪽
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j]) {
                    v.push_back(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int x = N - 1;
            for (int& k : v) board[i][x--] = k;
        }
    } else if (dir == 2) {
        // 위
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = 0; j < N; j++) {
                if (board[j][i]) {
                    v.push_back(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int y = 0;
            for (int& k : v) board[y++][i] = k;
        }
    } else if (dir == 3) {
        // 아래
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = N - 1; j >= 0; j--) {
                if (board[j][i]) {
                    v.push_back(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int y = N - 1;
            for (int& k : v) board[y--][i] = k;
        }
    }
}

int checkMax() {
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, board[i][j]);
        }
    }
    return mx;
}

int f(int n, int dir) {
    if (n == 5) return checkMax();
    checkSame(dir);
    moveBoard(dir);
    int ret = 0;
    int tmpBoard[20][20];
    copyBoard(tmpBoard, board);
    for (int d = 0; d < 4; d++) {
        ret = max(ret, f(n + 1, d));
        copyBoard(board, tmpBoard);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    cout << f(-1, -1) << nl;
    return 0;
}
