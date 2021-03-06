#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > 0) pos.push_back(a);
        else neg.push_back(a);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());
    int ans = 0;
    for (int i = 0; i < pos.size(); i += 2) {
        if (i == pos.size() - 1) ans += pos[i];
        else ans += max(pos[i] + pos[i + 1], pos[i] * pos[i + 1]);
    }
    for (int i = 0; i < neg.size(); i += 2) {
        if (i == neg.size() - 1) ans += neg[i];
        else ans += neg[i] * neg[i + 1];
    }
    cout << ans << "\n";
    return 0;
}
