#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void eratos(int n, vector<int>& v) {
    if (n <= 1) return;
    bool sieve[n + 1];
    for (int i = 2; i <= n; i++) sieve[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) v.push_back(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v;
    eratos(n, v);
    int start = 0, end = 0;
    int sum = 0, cnt = 0;
    while (true) {
        if (sum >= n) {
            if (sum == n) cnt++;
            sum -= v[start++];
        }
        else if (end == v.size()) break;
        else sum += v[end++];
    }
    cout << cnt << "\n";
    return 0;
}
