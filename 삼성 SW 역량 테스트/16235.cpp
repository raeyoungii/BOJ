#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int n, m, k;
int A[11][11];
int B[11][11];
vector<int> matrix[11][11];
int ans;

void removeTree(int r, int c, int dead) {
    for (int i = 0; i < dead; i++) {
        matrix[r][c].pop_back();
        ans--;
    }
}

void addTree(int r, int c) {
    for (int d = 0; d < 8; d++) {
        int ny = r + dy[d];
        int nx = c + dx[d];
        if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {
            matrix[ny][nx].push_back(1);
            ans++;
        }
    }
}

void springSummer() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // spring
            int dead = 0, sum = 0;
            sort(matrix[i][j].begin(), matrix[i][j].end());
            for (auto& age : matrix[i][j]) {
                if (age <= A[i][j]) {
                    A[i][j] -= age++;
                } else {
                    sum += age / 2;
                    dead++;
                }
            }
            removeTree(i, j, dead);
            // summer
            A[i][j] += sum;
        }
    }
}

void fallWinter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // fall
            for (auto& age : matrix[i][j]) {
                if (age % 5 == 0) addTree(i, j);
            }
            // winter
            A[i][j] += B[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        matrix[x][y].push_back(z);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = 5;
        }
    }
    ans = m;
    while(k--) { springSummer(); fallWinter(); }
    cout << ans;
    return 0;
}
