#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

struct Fish {
    int y, x, dist;
    Fish(int _y, int _x, int _dist) : y(_y), x(_x), dist(_dist) {};
};

struct compare {
    bool operator()(Fish a, Fish b) {
        if (a.dist == b.dist) {
            if (a.y == b.y) return a.x > b.x;
            return a.y > b.y;
        }
        return a.dist > b.dist;
    }
};

int n;
int matrix[20][20];
bool vst[20][20];
queue<Fish> q;

void bfs() {
    int size = 2, eat = 0, t = 0;
    while (true) {
        priority_queue<Fish, vector<Fish>, compare> pq;
        // 현재 위치에서 먹을 수 있는 모든 물고기들을 pq에 저장
        while (!q.empty()) {
            Fish cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ny = cur.y + dy[k];
                int nx = cur.x + dx[k];
                if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                    if (matrix[ny][nx] <= size && !vst[ny][nx]) {
                        q.emplace(ny, nx, cur.dist + 1);
                        vst[ny][nx] = true;
                    }
                    // 먹을 수 있는 물고기라면 pq에 저장
                    if (matrix[ny][nx] < size && matrix[ny][nx] != 0) {
                        pq.emplace(ny, nx, cur.dist + 1);
                    }
                }
            }
        }
        memset(vst, false, sizeof(vst));
        // pq가 비어있지 않으면 먹어야 할 물고기를 먹음
        if (!pq.empty()) {
            Fish cur = pq.top();
            pq.pop();
            matrix[cur.y][cur.x] = 0;
            eat++;
            t = cur.dist;
            q.emplace(cur.y, cur.x, cur.dist);
            vst[cur.y][cur.x] = true;
        }
        else {
            cout << t << "\n";
            break;
        }
        if (eat == size) {
            size++;
            eat = 0;
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
            if (matrix[i][j] == 9) {
                q.emplace(i, j, 0);
                matrix[i][j] = 0;
                vst[i][j] = true;
            }
        }
    }
    bfs();
    return 0;
}
