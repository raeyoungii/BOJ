#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, b);
    }
    vector<int> c;
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        c.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());
    priority_queue<int> pq;
    int idx = 0;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && v[idx].first <= c[i]) {
            pq.push(v[idx++].second);
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
