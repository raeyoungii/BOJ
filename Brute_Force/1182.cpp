#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, s;
int cnt;
int A[20];

void dfs(int i, int sum) {
    if (i == n) return;
    if (sum + A[i] == s) cnt++;
    dfs(i + 1, sum);
    dfs(i + 1, sum + A[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> A[i];
    cnt = 0;
    dfs(0, 0);
    cout << cnt << "\n";
    return 0;
}
