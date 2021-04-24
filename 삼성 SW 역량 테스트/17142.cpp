#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const int INF = 987654321;

int N, M;
int A[55][55];
int B[55][55];
int cnt[55][55];
vector<pair<int, int>> vp;

void copyAB(int a[][55], int b[][55]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = b[i][j];
        }
    }
}

bool checkZero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 0) return false;
        }
    }
    return true;
}

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 2) q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (B[ny][nx] == 0) {
                    B[ny][nx] = 2;
                    cnt[ny][nx] = cnt[y][x] + 1;
                    q.emplace(ny, nx);
                } else if (B[ny][nx] == -1) {
                    B[ny][nx] = 2;
                    cnt[ny][nx] = (!checkZero() ? cnt[y][x] + 1 : 0);
                    q.emplace(ny, nx);
                }
            }
        }
    }
}

int countTime() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 0) return INF;
            ret = max(ret, cnt[i][j]);
        }
    }
    return ret;
}

int dfs(int k, int n, int start) {
    if (k == n) {
        copyAB(B, A);
        memset(cnt, 0, sizeof(cnt));
        bfs();
        return countTime();
    }
    int ret = INF;
    for (int i = start; i < vp.size(); i++) {
        A[vp[i].first][vp[i].second] = 2;
        ret = min(ret, dfs(k + 1, n, i + 1));
        A[vp[i].first][vp[i].second] = -1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 2) {
                vp.emplace_back(i, j);
                A[i][j] = -1;
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= M; i++) {
        ans = min(ans, dfs(0, i, 0));
    }
    cout << (ans != INF ? ans : -1) << nl;
    return 0;
}
