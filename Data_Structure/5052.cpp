#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

bool solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        if (v[i].size() >= v[i + 1].size()) continue;
        if (v[i + 1].substr(0, v[i].size()) == v[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << nl;
    }
    return 0;
}
