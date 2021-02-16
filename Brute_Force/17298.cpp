#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> idx;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        while (!idx.empty() && a[idx.top()] < a[i]) {
            ans[idx.top()] = a[i];
            idx.pop();
        }
        idx.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n" [i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// TODO
