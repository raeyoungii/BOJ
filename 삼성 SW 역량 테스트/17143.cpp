#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct Shark {
    int s, d, z;
    Shark (int _s, int _d, int _z) : s(_s), d(_d), z(_z) {};
};

int R, C, M;
vector<Shark> board[110][110];

bool compare(const Shark& s1, const Shark& s2) { return s1.z > s2.z; }

int getShark(int p) {
    int ret = 0;
    for (int i = 1; i <= R; i++) {
        if (board[i][p].empty()) continue;
        Shark& cur = board[i][p][0];
        ret = cur.z;
        board[i][p].clear();
        break;
    }
    return ret;
}

void moveShark() {
    vector<Shark> tmpBoard[110][110];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].empty()) continue;
            Shark& cur = board[i][j][0];
            int MOD;
            if (cur.d < 2) MOD = (R - 1) * 2;
            else MOD = (C - 1) * 2;
            int speed = cur.s % MOD;
            int ny = i;
            int nx = j;
            while (speed--) {
                ny += dy[cur.d];
                nx += dx[cur.d];
                if (1 > ny || ny > R || 1 > nx || nx > C) {
                    cur.d = (cur.d % 2 ? cur.d - 1 : cur.d + 1);
                    ny += 2 * dy[cur.d];
                    nx += 2 * dx[cur.d];
                }
            }
            tmpBoard[ny][nx].push_back(cur);
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            board[i][j].clear();
            for (auto& x : tmpBoard[i][j]) board[i][j].push_back(x);
        }
    }
}

void removeShark() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].size() > 1) {
                sort(board[i][j].begin(), board[i][j].end(), compare);
                for (int k = 0; k < board[i][j].size() - 1; k++) {
                    board[i][j].pop_back();
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c].emplace_back(s, d - 1, z);
    }
    int ans = 0;
    for (int i = 1; i <= C; i++) {
        ans += getShark(i);
        moveShark();
        removeShark();
    }
    cout << ans << nl;
    return 0;
}
