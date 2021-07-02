#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

char A[64][64];

bool check(int y, int x, int n) {
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (A[i][j] != A[y][x]) return true;
        }
    }
    return false;
}

void f(int y, int x, int n) {
    if (check(y, x, n)) {
        cout << '(';
        f(y, x, n / 2);
        f(y, x + n / 2, n / 2);
        f(y + n / 2, x, n / 2);
        f(y + n / 2, x + n / 2, n / 2);
        cout << ')';
    } else cout << A[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    f(0, 0, N);
    return 0;
}
