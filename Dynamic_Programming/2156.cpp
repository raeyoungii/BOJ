#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int A[10101];
int dp[10101];

int f(int n) {
    if (n < 1) return 0;
    int& ret = dp[n];
    if (ret != -1) return ret;
    ret = f(n - 1);
    ret = max(ret, max(f(n - 2) + A[n], f(n - 3) + A[n - 1] + A[n]));
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    memset(dp, -1, sizeof(dp));
    cout << f(n) << nl;
    return 0;
}
