#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll k; cin >> k;
    ll start = 0, end = n * n;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }
        if (cnt >= k) end = mid - 1;
        else start = mid + 1;
    }
    cout << start << "\n";
    return 0;
}
