#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
bool vst[9] = {false,};
int arr2[8];

void dfs(int idx, int start, vector<int> arr) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr2[i] << " \n" [i == m - 1];
        }
        return;
    }
    for (int i = start; i < n; i++) {
        arr2[idx] = arr[i];
        dfs(idx + 1, i, arr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0, arr);
    return 0;
}
