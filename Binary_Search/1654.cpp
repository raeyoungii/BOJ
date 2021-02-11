#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n; cin >> k >> n;
    vector<ll> v(n);
    ll max_n;
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        max_n = max(max_n, v[i]);
    }
    ll start = 1, end = max_n;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += v[i] / mid;
        }
        if (cnt >= n) start = mid + 1;
        else end = mid - 1;
    }
    cout << end << "\n";
    return 0;
}
