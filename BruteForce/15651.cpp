#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[7];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " \n" [i == m - 1];
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[idx] = i;
        dfs(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dfs(0);
    return 0;
}
