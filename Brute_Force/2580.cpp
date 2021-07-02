#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int A[9][9];

void f(int k, int n, vector<pair<int, int>>& vp) {
    if (k == n) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << A[i][j] << ' ';
            }
            cout << nl;
        }
        exit(0);
    }
    int y = vp[k].first;
    int x = vp[k].second;
    bool ok[10] = {false,};
    for (int i = 0; i < 9; i++) {
        if (A[y][i]) ok[A[y][i]] = true;
        if (A[i][x]) ok[A[i][x]] = true;
    }
    for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
        for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
            if (A[i][j]) ok[A[i][j]] = true;
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (ok[i]) continue;
        A[y][x] = i;
        f(k + 1, n, vp);
        A[y][x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> vp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A[i][j];
            if (!A[i][j]) vp.emplace_back(i, j);
        }
    }
    f(0, (int) vp.size(), vp);
    return 0;
}
