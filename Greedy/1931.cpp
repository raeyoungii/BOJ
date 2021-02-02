#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end(), compare);

    int end_t = v[0].second;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (end_t <= v[i].first) {
            end_t = v[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
