#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};
const int sandDyx[4][9][2] = {
        {{-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {0, -2}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}},
        {{1, -1}, {1, 1}, {0, -1}, {0, 1}, {2, 0}, {0, -2}, {0, 2}, {-1, -1}, {-1, 1}},
        {{-1, 1}, {1, 1}, {-1, 0}, {1, 0}, {0, 2}, {-2, 0}, {2, 0}, {-1, -1}, {1, -1}},
        {{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {-2, 0}, {0, -2}, {0, 2}, {1, -1}, {1, 1}},
};
const int sandPct[9] = {10, 10, 7, 7, 5, 2, 2, 1, 1};

int n;
int A[550][550];

void sumTornado(int r, int c, int d) {
    int sand = A[r][c];
    if (!sand) return;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        A[r + sandDyx[d][i][0]][c + sandDyx[d][i][1]] += sand * sandPct[i] / 100;
        sum += sand * sandPct[i] / 100;
    }
    A[r + dy[d]][c + dx[d]] += sand - sum;
    A[r][c] = 0;
}

void moveTornado(int r, int c) {
    int k = 1, d = 0;
    int nr = r, nc = c;
    for (int i = 0; i < n; i++) {
        for (int rotate = 0; rotate < 2; rotate++) {
            for (int j = 0; j < k; j++) {
                if (i == n - 1 && j == k - 1) return;
                nr = nr + dy[d];
                nc = nc + dx[d];
                sumTornado(nr, nc, d);
            }
            d = (d + 1) % 4;
        }
        k++;
    }
}

int getSand() {
    int cnt = 0;
    for (int i = 0; i < n + 4; i++) {
        for (int j = 0; j < n + 4; j++) {
            if (2 <= i && i < n + 2 && 2 <= j && j < n + 2) continue;
            cnt += A[i][j];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i < n + 2; i++) {
        for (int j = 2; j < n + 2; j++) {
            cin >> A[i][j];
        }
    }
    moveTornado(n / 2 + 2, n / 2 + 2);
    cout << getSand();
    return 0;
}
