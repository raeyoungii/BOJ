#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool compare(pair<int, int>a, pair<int, int> b) { return a.second > b.second; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int p, d; cin >> p >> d;
        v.emplace_back(p, d);
    }
    sort(v.begin(), v.end(), compare);
    priority_queue<int> pq;
    int idx = 0;
    int ans = 0;
    for (int i = 10000; i > 0; i--) {
        while (idx < n && i <= v[idx].second) {
            pq.push(v[idx++].first);
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
