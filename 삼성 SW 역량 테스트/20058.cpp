#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, Q, L;
int vst[64][64];
int A[64][64];

void rotate(int r, int c, int n) {
    int B[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][n - 1 - j] = A[r + i][c + j];
        }
    }
    for (int i = 0; i <  n; i++) {
        for (int j = 0; j < n; j++) {
            A[r + i][c + j] = B[i][j];
        }
    }
}

void checkIce(int r, int c, vector<pair<int, int> >& rc) {
    if (!A[r][c]) return;
    int cnt = 0;
    for (int d = 0; d < 4; d++) {
        int nr = r + dy[d];
        int nc = c + dx[d];
        if (0 > nr || nr >= 1 << N || 0 > nc || nc >= 1 << N) cnt++;
        else if (A[nr][nc] == 0) cnt++;
    }
    if (cnt > 1) rc.emplace_back(r, c);
}

void fireStorm() {
    for (int i = 0; i < 1 << N; i += 1 << L) {
        for (int j = 0; j < 1 << N; j += 1 << L) {
            rotate(i, j, 1 << L);
        }
    }
    vector<pair<int, int> > rc;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < 1 << N; j++) {
            checkIce(i, j, rc);
        }
    }
    for (auto& pos : rc) A[pos.first][pos.second]--;
}

int dfs(int r, int c, int cnt) {
    vst[r][c] = 1;
    for (int d = 0; d < 4; d++) {
        int nr = r + dy[d];
        int nc = c + dx[d];
        if (0 <= nr && nr < 1 << N && 0 <= nc && nc < 1 << N)
            if (A[nr][nc] && !vst[nr][nc])
                cnt = dfs(nr, nc, cnt + 1);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < 1 << N; j++) {
            cin >> A[i][j];
        }
    }
    while (Q--) {
        cin >> L;
        fireStorm();
    }
    int mx = 0, cnt = 0;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < 1 << N; j++) {
            cnt += A[i][j];
            if (A[i][j] && !vst[i][j]) mx = max(mx, dfs(i, j , 1));
        }
    }
    cout << cnt << nl << mx << nl;
    return 0;
}
