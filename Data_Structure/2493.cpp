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
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    for (int& x : ans) cout << x << ' ';
    return 0;
}
