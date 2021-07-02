#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int MAX = 1e9 + 7;

int N;
int mx = -MAX, mn = MAX;
int A[11];
int op[4];

int calc(int i, int n, int idx) {
    int ret;
    if (i == 0) ret = n + A[idx];
    else if (i == 1) ret = n - A[idx];
    else if (i == 2) ret = n * A[idx];
    else ret = n / A[idx];
    return ret;
}


void f(int n, int idx) {
    if (idx == N) {
        mx = max(mx, n);
        mn = min(mn, n);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            f(calc(i, n, idx), idx + 1);
            op[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    f(A[0], 1);
    cout << mx << nl << mn;
    return 0;
}
