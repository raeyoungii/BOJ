#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    int sum = 0, max_n = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        max_n = max(max_n, v[i]);
    }
    int start = max_n, end = sum;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cnt = 0, tmp_sum= 0;
        for (int i = 0; i < n; i++) {
            if (tmp_sum + v[i] > mid) {
                cnt++;
                tmp_sum = 0;
            }
            tmp_sum += v[i];
        }
        cnt++;
        if (cnt <= m) end = mid - 1;
        else start = mid + 1;
    }
    cout << start << "\n";
    return 0;
}
