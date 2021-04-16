#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k; cin >> k;
    ll tmp = 1, cnt = 0;
    while (tmp < k) tmp *= 2;
    tmp /= 2;
    while (k > 1) {
        k -= tmp;
        while (tmp >= k) tmp /= 2;
        cnt++;
    }
    if (cnt % 2) cout << 1;
    else cout << 0;
    return 0;
}
