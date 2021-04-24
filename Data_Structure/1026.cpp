#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int A[55];
int B[55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    sort(A, A + n);
    sort(B, B + n, greater<>());
    int s = 0;
    for (int i = 0; i < n; i++) s += A[i] * B[i];
    cout << s << nl;
    return 0;
}
