#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    vector<int> ab, cd;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    for (int i = 0; i < n * n; i++) {
        int cd_lb = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        int cd_ub = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        ans += cd_ub - cd_lb;
    }
    cout << ans << "\n";
    return 0;
}
