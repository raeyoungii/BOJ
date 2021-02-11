#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

struct Cctv {
    int y, x, type, dir;
    Cctv(int _y, int _x, int _type, int _dir): y(_y), x(_x), type(_type), dir(_dir) {};
};

int n, m;
int ans = INT_MAX;
int matrix_tmp[8][8];
int matrix[8][8];
vector<Cctv> cctv_list;

int getAns() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_tmp[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void fill(int y, int x, int d) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    while (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (matrix_tmp[ny][nx] == 6) break;
        if (matrix_tmp[ny][nx] == 0) matrix_tmp[ny][nx] = -1;
        ny += dy[d];
        nx += dx[d];
    }
}

void activate() {
    memcpy(matrix_tmp, matrix, sizeof(matrix_tmp));
    for (auto & cctv : cctv_list) {
        int cur_y = cctv.y;
        int cur_x = cctv.x;
        int cur_d = cctv.dir;
        switch (cctv.type) {
            case 1:
                fill(cur_y, cur_x, cur_d % 4);
                break;
            case 2:
                fill(cur_y, cur_x, cur_d % 4);
                fill(cur_y, cur_x, (cur_d + 2) % 4);
                break;
            case 3:
                fill(cur_y, cur_x, cur_d % 4);
                fill(cur_y, cur_x, (cur_d + 1) % 4);
                break;
            case 4:
                fill(cur_y, cur_x, cur_d % 4);
                fill(cur_y, cur_x, (cur_d + 1) % 4);
                fill(cur_y, cur_x, (cur_d + 2) % 4);
                break;
            case 5:
                fill(cur_y, cur_x, cur_d % 4);
                fill(cur_y, cur_x, (cur_d + 1) % 4);
                fill(cur_y, cur_x, (cur_d + 2) % 4);
                fill(cur_y, cur_x, (cur_d + 3) % 4);
                break;
        }
    }
}

void dfs(int idx) {
    if (idx == cctv_list.size()) {
        activate();
        ans = min(ans, getAns());
        return;
    }
    for (int i = 0; i < 4; i++) {
        cctv_list[idx].dir = i;
        dfs(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k; cin >> k;
            matrix[i][j] = k;
            if (1 <= k && k <= 5) {
                cctv_list.emplace_back(i, j, k, 0);
            }
        }
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}
