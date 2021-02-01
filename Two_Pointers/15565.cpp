#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int start = 0, end = 0;
    int lion_cnt = 0, min_cnt = n + 1;
    while (true) {
        if (lion_cnt >= k) {
            min_cnt = min(min_cnt, end - start);
            if (v[start] == 1) lion_cnt--;
            start++;
        }
        else if (end == n) break;
        else {
            if (v[end] == 1) lion_cnt++;
            end++;
        }
    }
    if (min_cnt == n + 1) cout << "-1\n";
    else cout << min_cnt << "\n";
    return 0;
}
