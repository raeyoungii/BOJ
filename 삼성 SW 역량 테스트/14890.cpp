#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int N, L;
int A[110][110];
int B[110][110];

bool solve1(int y) {
    for (int i = 0; i < N - 1; i++) {
        if(abs(A[y][i + 1] - A[y][i]) > 1) return false;
        if(abs(A[y][i + 1] - A[y][i]) == 0) continue;
        if (A[y][i] < A[y][i + 1]) {
            int x = i;
            for (int j = 0; j < L; j++) {
                if (0 > x || B[y][x] || A[y][i] != A[y][x]) return false;
                B[y][x--] = 1;
            }
        } else {
            int x = i + 1;
            for (int j = 0; j < L; j++) {
                if (N <= x || B[y][x] || A[y][i + 1] != A[y][x]) return false;
                B[y][x++] = 1;
            }
        }
    }
    return true;
}

bool solve2(int x) {
    for (int i = 0; i < N - 1; i++) {
        if(abs(A[i + 1][x] - A[i][x]) > 1) return false;
        if(abs(A[i + 1][x] - A[i][x]) == 0) continue;
        if (A[i][x] < A[i + 1][x]) {
            int y = i;
            for (int j = 0; j < L; j++) {
                if (0 > y || B[y][x] || A[i][x] != A[y][x]) return false;
                B[y--][x] = 1;
            }
        } else {
            int y = i + 1;
            for (int j = 0; j < L; j++) {
                if (N <= y || B[y][x] || A[i + 1][x] != A[y][x]) return false;
                B[y++][x] = 1;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        memset(B, 0, sizeof(B));
        if(solve1(i)) cnt++;
        memset(B, 0, sizeof(B));
        if(solve2(i)) cnt++;
    }
    cout << cnt << nl;
    return 0;
}
