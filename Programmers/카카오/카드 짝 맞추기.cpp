#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const int INF = 1e9;

struct Point {
    int y, x, d = 0;
    Point(int _y, int _x) : y(_y), x(_x) {};
    Point(int _y, int _x, int _d) : y(_y), x(_x), d(_d) {};
};

struct compare {
    bool operator() (const Point &a, const Point &b) { return a.d > b.d; }
};

bool check(vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) return false;
        }
    }
    return true;
}

int dijkstra(vector<vector<int>> &board, int y1, int x1, int y2, int x2) {
    priority_queue<Point, vector<Point>, compare> pq;
    pq.emplace(y1, x1, 0);
    int dist[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dist[i][j] = INF;
        }
    }
    dist[y1][x1] = 0;
    while (!pq.empty()) {
        Point cur = pq.top();
        pq.pop();
        if (dist[cur.y][cur.x] < cur.d) continue;
        if (cur.y == y2 && cur.x == x2) return cur.d;
        for (int d = 0; d < 4; d++) {
            int ny = cur.y;
            int nx = cur.x;
            int cnt = 1;
            while (0 <= ny + dx[d] && ny + dx[d] < 4 && 0 <= nx + dx[d] && nx + dx[d] < 4) {
                ny += dy[d];
                nx += dx[d];
                cnt++;
                if (board[ny][nx] != 0) break;
                if (dist[ny][nx] > cur.d + cnt) {
                    dist[ny][nx] = cur.d + cnt;
                    pq.emplace(ny, nx, cur.d + cnt);
                }
            }
            if (dist[ny][nx] > cur.d + 1) {
                dist[ny][nx] = cur.d + 1;
                pq.emplace(ny, nx, cur.d + 1);
            }
        }
    }
}

int f(vector<vector<int>> &board, int y, int x) {
    if (check(board)) return 0; // 전부 뒤집음
    int ret = INF;
    // 카드 k 뒤집기
    for (int k = 1; k <= 6; k++) {
        vector<Point> p;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (board[i][j] == k)
                    p.emplace_back(i, j);

        if (p.empty()) continue;

        // 앞에꺼를 먼저 뒤집음
        int cand1 = dijkstra(board, y, x, p[0].y, p[0].x) + dijkstra(board, p[0].y, p[0].x, p[1].y, p[1].x) + 2;

        // 뒤에꺼를 먼저 뒤집음
        int cand2 = dijkstra(board, y, x, p[1].y, p[1].x) + dijkstra(board, p[1].y, p[1].x, p[0].y, p[0].x) + 2;

        // dfs
        board[p[0].y][p[0].x] = 0;
        board[p[1].y][p[1].x] = 0;

        ret = min(ret, min(cand1 + f(board, p[1].y, p[1].x), cand2 + f(board, p[0].y, p[0].x)));

        board[p[0].y][p[0].x] = k;
        board[p[1].y][p[1].x] = k;
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = f(board,r,c);
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
