#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
bool vst[9] = {false,};
int arr[8];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " \n" [i == m - 1];
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vst[i]) continue;
        vst[i] = true;
        arr[idx] = i;
        dfs(idx + 1);
        vst[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dfs(0);
    return 0;
}
