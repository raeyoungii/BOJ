#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int N;
int D[10101][6];

int f(int n, int prev) {
    if (n == N) return 0;
    int ret, now;
    for (int i = 0; i < 6; i++) {
        if (D[n][i] == prev) { now = i; break; }
    }
    int mx = -1;
    for (int i = 0; i < 6; i++) {
        if (i == now || i == (now + 3) % 6) continue;
        mx = max(mx, D[n][i]);
    }
    ret = f(n + 1, D[n][(now + 3) % 6]) + mx;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D[i][0] >> D[i][1] >> D[i][2] >> D[i][4] >> D[i][5] >> D[i][3];
    }
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans = max(ans, f(0, D[0][i]));
    }
    cout << ans << nl;
    return 0;
}
