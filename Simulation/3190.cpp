#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int matrix[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int k; cin >> k;
    while (k--) {
        int r, c; cin >> r >> c;
        matrix[r - 1][c - 1] = 2;
    }
    int l; cin >> l;
    queue<pair<int, char>> q;
    while (l--) {
        int x; char c; cin >> x >> c;
        q.emplace(x, c);
    }
    deque<pair<int, int>> dq;
    int dq_d = 0;
    int t = 0;
    matrix[0][0] = 1;
    dq.emplace_front(0, 0);
    while (true) {
        if (t == q.front().first) {
            if (q.front().second == 'L') dq_d = (dq_d + 3) % 4;
            else dq_d = (dq_d + 1) % 4;
            q.pop();
        }
        t++;
        int ny = dq.front().first + dy[dq_d];
        int nx = dq.front().second + dx[dq_d];
        if (0 <= ny && ny < n && 0 <= nx && nx < n) {
            if (matrix[ny][nx] != 1) {
                if (matrix[ny][nx] == 0) {
                    matrix[dq.back().first][dq.back().second] = 0;
                    dq.pop_back();
                }
                matrix[ny][nx] = 1;
                dq.emplace_front(ny, nx);
            } else break;
        } else break;
    }
    cout << t << "\n";
    return 0;
}
