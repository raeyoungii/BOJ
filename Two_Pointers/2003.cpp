#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int start = 0, end = 0, sum = 0, cnt = 0;
    while (true) {
        if (sum >= m) sum -= v[start++];
        else if (end == n) break;
        else sum += v[end++];
        if (sum == m) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
