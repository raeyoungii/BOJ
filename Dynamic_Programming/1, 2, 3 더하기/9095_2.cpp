#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int D[11];

int dfs(int pos) {
    if (pos == 0) return 1;
    int& ret = D[pos];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= 3; i++) {
        if (pos - i < 0) continue;
        ret += dfs(pos - i);
    }
    return ret;
}

// 1, 2, 3 더하기
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    memset(D, -1, sizeof(D));
    while(t--) {
        int n; cin >> n;
        cout << dfs(n) << nl;
    }
    return 0;
}
