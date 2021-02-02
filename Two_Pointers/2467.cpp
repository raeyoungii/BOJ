#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int l = 0, r = n - 1;
    int al = v[l], ar = v[r], res = INT_MAX;
    while (l < r) {
        int tmp = v[l] + v[r];
        if (abs(tmp) < abs(res)) {
            res = tmp;
            al = v[l];
            ar = v[r];
        }
        if (tmp < 0) l++;
        else r--;
    }
    cout << al << " " << ar << "\n";
    return 0;
}
