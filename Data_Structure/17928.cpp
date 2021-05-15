#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    stack<int> s;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    for (int& x : ans) cout << x << ' ';
    return 0;
}
