#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;

int rotateArr(int x1, int y1, int x2, int y2, vector<vector<int>>& A) {
    deque<int> dq;
    int mn = INF;
    int nx = x1, ny = y1;
    int idx = 0;
    while (ny < y2) dq.push_back(A[nx][ny++]);
    while (nx < x2) dq.push_back(A[nx++][ny]);
    while (ny > y1) dq.push_back(A[nx][ny--]);
    while (nx > x1) dq.push_back(A[nx--][ny]);
    dq.push_front(dq.back());
    dq.pop_back();
    while (ny < y2) A[nx][ny++] = dq[idx++];
    while (nx < x2) A[nx++][ny] = dq[idx++];
    while (ny > y1) A[nx][ny--] = dq[idx++];
    while (nx > x1) A[nx--][ny] = dq[idx++];
    for (auto& n : dq) mn = min(mn, n);
    return mn;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> A(rows + 1, vector<int>(columns + 1, 0));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            A[i][j] = (i - 1) * columns + j;
        }
    }
    for (auto& query : queries) {
        int mn = rotateArr(query[0], query[1], query[2], query[3], A);
        answer.push_back(mn);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};
    vector<int> v = solution(rows, columns, queries);
    for(auto& x : v) cout << x << ' ';
    return 0;
}
