#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int N, M;
int A[100];

int f(int start, int k, int sum) {
    if (k == 3) {
        if (sum > M) return 0;
        else return sum;
    }
    int ret = 0;
    for (int i = start; i < N; i++) {
        ret = max(ret, f(i + 1, k + 1, sum + A[i]));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << f(0, 0, 0) << nl;
    return 0;
}
