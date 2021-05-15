#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

void solve() {
    int N; cin >> N;
    vector<pair<int, int>> vp;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        vp.emplace_back(a, b);
    }
    sort(vp.begin(), vp.end());
    int cnt = 1;
    int k = vp[0].second;
    for (int i = 1; i < N; i++) {
        if (k < vp[i].second) continue;
        k = vp[i].second;
        cnt++;
    }
    cout << cnt << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
