#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

ll f(ll x) {
    if (x == 1) return 0;
    ll n = 1;
    while (n < x) n *= 2;
    return 1 - f(x - n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k; cin >> k;
    cout << f(k);
    return 0;
}
