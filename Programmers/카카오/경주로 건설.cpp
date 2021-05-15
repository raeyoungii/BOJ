#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

struct Car {
    int y, x, d;
    Car(int _y, int _x, int _d) : y(_y), x(_x), d(_d) {};
};

int N;
int cost[25][25][4];

void bfs(vector<vector<int>>& board) {
    queue<Car> q;
    for (int d = 0; d < 4; d++) {
        q.emplace(0, 0, d);
    }
    while (!q.empty()) {
        Car cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];
            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (board[ny][nx] == 1 || d == (cur.d + 2) % 4) continue;
                int newCost = cost[cur.y][cur.x][cur.d] + (d == cur.d ? 100 : 600);
                if (!cost[ny][nx][d] || newCost < cost[ny][nx][d]) {
                    cost[ny][nx][d] = newCost;
                    q.emplace(ny, nx, d);
                }
            }
        }
    }
}

int solution(vector<vector<int>>& board) {
    int answer = INF;
    N = (int) board.size();
    bfs(board);
    for (int d = 0; d < 4; d++) {
        int totCost = cost[N - 1][N - 1][d];
        if (totCost) answer = min(answer, totCost);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0},
                                 {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}};
    cout << solution(board) << nl;
    return 0;
}
