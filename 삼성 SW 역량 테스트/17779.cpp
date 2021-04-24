#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;

int N;
int A[21][21];

// 조건을 잘 정리하면 아래와 같이 1지구부터 4지구를 정의할 수 있다.
bool isFirst(int i, int j, int y, int x, int d1, int d2) {
    return (i < y + d1 && j <= x && !(i >= y && j >= x - (i - y)));
}

bool isSecond(int i, int j, int y, int x, int d1, int d2) {
    return (i <= y + d2 && j > x && !(i >= y && j <= x + (i - y)));
}

bool isThird(int i, int j, int y, int x, int d1, int d2) {
    return (i >= y + d1 && j < x - d1 + d2 && !(i <= y + d1 + d2 && j >= (x - d1 + d2 - (y + d1 + d2 - i))));
}

bool isFourth(int i, int j, int y, int x, int d1, int d2) {
    return (i > y + d2 && j >= x - d1 + d2 && !(i <= y + d1 + d2 && j <= (x - d1 + d2 + (y + d1 + d2 - i))));
}

int func(int y, int x, int d1, int d2) {
    vector<int> populations(5);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (isFirst(i, j, y, x, d1, d2)) {
                populations[0] += A[i][j];
            } else if (isSecond(i, j, y, x, d1, d2)) {
                populations[1] += A[i][j];
            } else if (isThird(i, j, y, x, d1, d2)) {
                populations[2] += A[i][j];
            } else if (isFourth(i, j, y, x, d1, d2)) {
                populations[3] += A[i][j];
            } else {
                populations[4] += A[i][j];
            }
        }
    }
    sort(populations.begin(), populations.end());
    return populations[4] - populations[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    int ans = INF;
    // 1 <= y < y + d1 + d2 <= N
    // 1 <= y <= N - d1 - d2
    // d1, d2 >= 1
    // 1 <= y <= N-2
    for (int y = 1; y <= N - 2; y++) {
        // 1 <= x - d1 < x < x + d2 <= N
        // 1 + d1 <= x <= N - d2
        // d1, d2 >= 1
        // 2 <= x <= N - 1
        for (int x = 2; x <= N - 1; x++) {
            for (int d1 = 1; d1 <= N - y - 1 && d1 <= x - 1; d1++) {
                for (int d2 = 1; d2 <= N - y - 1 && d2 <= N - x; d2++) {
                    ans = min(ans, func(y, x, d1, d2));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
