#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        ans += sum;
    }
    cout << ans << "\n";
    return 0;
}
