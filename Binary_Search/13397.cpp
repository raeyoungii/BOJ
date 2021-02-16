#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int start = 0, end = *max_element(v.begin(), v.end());
    while (start <= end) {
        int mid = (start + end) / 2;
        int max_n = 0, min_n = 10001, cnt = 1;
        for (int i = 0; i < n; i++) {
            if (max_n < v[i]) max_n = v[i];
            if (min_n > v[i]) min_n = v[i];
            if (max_n - min_n > mid) {
                cnt++;
                max_n = v[i];
                min_n = v[i];
            }
        }
        if (cnt <= m) end = mid - 1;
        else start = mid + 1;
    }
    cout << start << "\n";
    return 0;
}

// TODO
