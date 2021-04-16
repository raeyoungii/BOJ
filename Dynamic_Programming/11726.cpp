#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int MOD = 1e4 + 7;

int D[1010];

int dfs(int w) {
    if (w <= 1) return 1;
    int& ret = D[w];
    if (ret != -1) return ret;
    return ret = (dfs(w - 1) + dfs(w - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    memset(D, -1, sizeof(D));
    cout << dfs(n);
    return 0;
}
