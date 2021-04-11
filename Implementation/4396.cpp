#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
char A[10][10];
char B[10][10];

char chk(int y, int x) {
    char cnt = '0';
    if (0 < y && A[y - 1][x] == '*') cnt++;
    if (y < n - 1 && A[y + 1][x] == '*') cnt++;
    if (0 < x && A[y][x - 1] == '*') cnt++;
    if (x < n - 1 && A[y][x + 1] == '*') cnt++;
    if (0 < y && 0 < x && A[y - 1][x - 1] == '*') cnt++;
    if (0 < y && x < n - 1 && A[y - 1][x + 1] == '*') cnt++;
    if (y < n - 1 && 0 < x && A[y + 1][x - 1] == '*') cnt++;
    if (y < n - 1 && x < n - 1 && A[y + 1][x + 1] == '*') cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
            if (B[i][j] == 'x') {
                if (A[i][j] == '*') flag = true;
                B[i][j] = chk(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flag && A[i][j] == '*') cout << '*';
            else cout << B[i][j];
        }
        cout << "\n";
    }
    return 0;
}
