#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct FireBall {
    int r, c, m, s, d; // 행, 열, 질량, 속력, 방향
    FireBall(int _r, int _c, int _m, int _s, int _d) : r(_r), c(_c), m(_m), s(_s), d(_d) {};
};

int n, m, k;
vector<FireBall> matrix[50][50];

FireBall move(FireBall f) {
    int mv = f.s % n;
    f.r += dy[f.d] * mv;
    if (f.r < 0) f.r += n;
    else if (f.r > n - 1) f.r -= n;
    f.c += dx[f.d] * mv;
    if (f.c < 0) f.c += n;
    else if (f.c > n - 1) f.c -= n;
    return f;
}

void moveFireBall() {
    vector<FireBall> matrix_tmp[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto & f : matrix[i][j]) {
                FireBall nf = move(f);
                matrix_tmp[nf.r][nf.c].push_back(nf);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrix_tmp[i][j];
        }
    }
}

void sumFireBall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j].size() > 1) {
                int sum_m = 0, sum_s = 0, cnt = matrix[i][j].size();
                bool even = false, odd = false;
                for (auto & f : matrix[i][j]) {
                    sum_m += f.m;
                    sum_s += f.s;
                    if (f.d % 2 == 0) even = true;
                    else odd = true;
                }
                matrix[i][j].clear();
                if (sum_m / 5 == 0) continue;
                for (int l = 0; l < 4; l++) {
                    if (even && odd)
                        matrix[i][j].emplace_back(i, j, sum_m / 5, sum_s / cnt, l * 2 + 1);
                    else
                        matrix[i][j].emplace_back(i, j, sum_m / 5, sum_s / cnt, l * 2);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int R, C, M, S, D; cin >> R >> C >> M >> S >> D;
        matrix[R - 1][C - 1].emplace_back(R - 1, C - 1, M, S, D);
    }
    while (k--) {
        moveFireBall();
        sumFireBall();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto & f : matrix[i][j]) {
                ans += f.m;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
