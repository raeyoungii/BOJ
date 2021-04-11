#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int A[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i + 1] > A[i + 2]) {
            int two = min(A[i], A[i + 1] - A[i + 2]);
            ans += 5 * two;
            A[i] -= two; A[i + 1] -= two;

            int three = min(A[i], min(A[i + 1], A[i + 2]));
            ans += 7 * three;
            A[i] -= three; A[i + 1] -= three; A[i + 2] -= three;
        } else {
            int three = min(A[i], min(A[i + 1], A[i + 2]));
            ans += 7 * three;
            A[i] -= three; A[i + 1] -= three; A[i + 2] -= three;

            int two = min(A[i], A[i + 1]);
            ans += 5 * two;
            A[i] -= two; A[i + 1] -= two;
        }
        ans += 3 * A[i];
    }
    cout << ans << "\n";
    return 0;
}
