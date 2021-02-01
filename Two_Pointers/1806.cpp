#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 100001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int start = 0, end = 0, sum = 0, min_cnt = MAX;
    while (true) {
        if (sum >= s) {
            min_cnt = min(min_cnt, end - start);
            sum -= v[start++];
        }
        else if (end == n) break;
        else sum += v[end++];
    }
    if (min_cnt == MAX) cout << "0\n";
    else cout << min_cnt << "\n";
    return 0;
}
