#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 987654321;
int n;
int w[16][16];
int dp[16][1 << 16];

int tsp(int cur, int vst) {
    int &ret = dp[cur][vst];
    if (ret != -1) return ret;
    if (vst == (1 << n) - 1) {
        if (w[cur][0] != 0) return w[cur][0];
        return INF;
    }
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (w[cur][i] == 0 || vst & (1 << i)) continue;
        ret = min(ret, w[cur][i] + tsp(i, vst | (1 << i)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << "\n";
    return 0;
}
