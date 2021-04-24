#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;

int N, M, H;
int A[31][11];

bool check() {
    for (int i = 1; i <= N; i++) {
        int k = i;
        for (int j = 1; j <= H; j++) {
            if (A[j][k - 1]) k--;
            else if (A[j][k]) k++;
        }
        if (k != i) return false;
    }
    return true;
}

int f(int k, int start) {
    if (k > 3) return INF;
    if (check()) return k;
    int ret = INF;
    for (int i = start; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (A[i][j] || A[i][j - 1] || A[i][j + 1]) continue;
            A[i][j] = 1;
            ret = min(ret, f(k + 1, i));
            A[i][j] = 0;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        A[a][b] = 1;
    }
    int ans = f(0, 1);
    cout << (ans != INF ? ans : -1) << nl;
    return 0;
}
