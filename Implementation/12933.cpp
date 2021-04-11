#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    vector<int> q, u, a, c, k;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'q') q.push_back(i);
        else if (s[i] == 'u') u.push_back(i);
        else if (s[i] == 'a') a.push_back(i);
        else if (s[i] == 'c') c.push_back(i);
        else k.push_back(i);
    }
    if (q.size() != u.size() || q.size() != a.size() || q.size() != c.size() || q.size() != k.size()) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < (int) q.size(); i++) {
        if (q[i] > u[i] || u[i] > a[i] || a[i] > c[i] || c[i] > k[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    int mx = 0, pos = 0;
    for (int i = 0; i < (int) q.size(); i++) {
        while (k[pos] < q[i]) pos++;
        mx = max(mx, i - pos + 1);
    }
    cout << mx << "\n";
    return 0;
}
