#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll res = LLONG_MAX;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            ll tmp = (ll) v[i] + (ll) v[l] + (ll) v[r];
            if (abs(tmp) < abs(res)) {
                res = tmp;
                ans = {v[i], v[l], v[r]};
            }
            if (tmp < 0) l++;
            else r--;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " \n" [i == 2];
    }
    return 0;
}
