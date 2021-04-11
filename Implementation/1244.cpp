#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int A[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int m; cin >> m;
    while (m--) {
        int g, sw; cin >> g >> sw;
        if (g == 1) {
            for (int i = sw; i <= n; i += sw) A[i] = !A[i];
        } else {
            int l = sw, r = sw;
            while (true) {
                if (l < 1 || r > n) break;
                if (A[l] != A[r]) break;
                l--; r++;
            }
            for (int i = l + 1; i <= r - 1; i++) A[i] = !A[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " \n" [i % 20 == 0];
    }
    return 0;
}
