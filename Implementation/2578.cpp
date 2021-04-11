#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool matrix[5][5];

int chk() {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (matrix[i][0] && matrix[i][1] && matrix[i][2] && matrix[i][3] && matrix[i][4]) cnt++;
    }
    for (int i = 0; i < 5; i++) {
        if (matrix[0][i] && matrix[1][i] && matrix[2][i] && matrix[3][i] && matrix[4][i]) cnt++;
    }
    if (matrix[0][0] && matrix[1][1] && matrix[2][2] && matrix[3][3] && matrix[4][4]) cnt++;
    if (matrix[4][0] && matrix[3][1] && matrix[2][2] && matrix[1][3] && matrix[0][4]) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> pos(26);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int a; cin >> a;
            pos[a] = make_pair(i, j);
        }
    }
    for (int i = 1; i <= 25; i++) {
        int n; cin >> n;
        matrix[pos[n].first][pos[n].second] = true;
        if (chk() >= 3) { cout << i << "\n"; break; }
    }
    return 0;
}
