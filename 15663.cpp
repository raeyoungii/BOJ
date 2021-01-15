#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
bool vst[10001] = {false,};
int arr[8];
int arr2[8];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr2[i] << " \n" [i == m - 1];
        }
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (vst[i] || prev == arr[i]) continue;
        vst[i] = true;
        arr2[idx] = arr[i];
        prev = arr[i];
        dfs(idx + 1);
        vst[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);
    return 0;
}
