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
    int ab_idx = 0;
    int cd_idx = (int) cd.size() - 1;
    while (ab_idx < ab.size() && cd_idx >= 0) {
        int ab_sum = ab[ab_idx];
        int cd_sum = cd[cd_idx];
        ll ab_cnt = 0, cd_cnt = 0;
        int sum = ab_sum + cd_sum;
        if (sum == 0) {
            while (ab_idx < ab.size() && ab_sum == ab[ab_idx]) {
                ab_idx++;
                ab_cnt++;
            }
            while (cd_idx >= 0 && cd_sum == cd[cd_idx]) {
                cd_idx--;
                cd_cnt++;
            }
            ans += ab_cnt * cd_cnt;
        }
        else if (sum > 0) cd_idx--;
        else ab_idx++;
    }
    cout << ans << "\n";
    return 0;
}
