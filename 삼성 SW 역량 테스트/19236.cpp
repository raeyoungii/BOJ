#include <iostream>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Fish {
    int y, x, dir;
    bool dead;
};

int board[4][4];
Fish fish[17];

void copy(int a[][4], int b[][4], Fish c[], Fish d[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = b[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) c[i] = d[i];
}

void moveFish(int r, int c) {
    for (int i = 1; i <= 16; i++) {
        Fish& cur = fish[i];
        // 물고기가 죽었다면 패스
        if (cur.dead) continue;
        for (int d = 0; d < 8; d++) {
            int ny = cur.y + dy[(cur.dir + d) % 8];
            int nx = cur.x + dx[(cur.dir + d) % 8];
            if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
                // 상어의 위치 패스
                if (ny == r && nx == c) continue;
                Fish& dest = fish[board[ny][nx]];
                swap(board[cur.y][cur.x], board[dest.y][dest.x]);
                swap(cur.y, dest.y);
                swap(cur.x, dest.x);
                cur.dir = (cur.dir + d) % 8;
                break;
            }
        }
    }
}

int dfs(int r, int c) {
    Fish& cur = fish[board[r][c]];
    // 잡아먹음
    cur.dead = true;
    // 물고기 이동
    moveFish(r, c);
    int ny = cur.y;
    int nx = cur.x;
    // 현재 물고기의 값
    int ret = board[r][c], mx = 0;
    // 보드, 물고기 복사
    int tmpBoard[4][4];
    Fish tmpFish[17];
    copy(tmpBoard, board, tmpFish, fish);
    for (int i = 0; i < 3; i++) {
        ny += dy[cur.dir];
        nx += dx[cur.dir];
        if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
            Fish& dest = fish[board[ny][nx]];
            // 물고기가 살아있다면
            if (!dest.dead) {
                // 이동했을 때 최댓값
                mx = max(mx, dfs(ny, nx));
                // 보드, 물고기 복원
                copy(board, tmpBoard, fish, tmpFish);
            }
        }
    }
    // 이동시 최댓값을 더해줌 (이동 못하면 현재 물고기값 반환)
    ret += mx;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b; cin >> a >> b;
            fish[a].y = i;
            fish[a].x = j;
            fish[a].dir = b - 1;
            fish[a].dead = false;
            board[i][j] = a;
        }
    }
    cout << dfs(0, 0) << nl;
    return 0;
}
