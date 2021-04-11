#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll A[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> A[i];
    if (n <= m) {
        cout << n << "\n";
        return 0;
    }
    ll start = 0, end = 60000000000;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = m;
        for (int i = 1; i <= m; i++) {
            cnt += mid / A[i];
        }
        if (n <= cnt) end = mid - 1;
        else start = mid + 1;
    }
    ll cnt = m;
    for (int i = 1; i <= m; i++) {
        cnt += (start - 1) / A[i];
    }
    for (int i = 1; i <= m; i++) {
        if (start % A[i] == 0) cnt++;
        if (cnt == n) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
