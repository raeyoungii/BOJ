#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const ll MOD = (ll) pow(2, 64);

ll M, N;
ll A[101010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    ll sum = -M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A, A + N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll k = min(A[i], sum / (N - i));
        ans = (ans + k * k) % MOD;
        sum -= k;
    }
    cout << ans << nl;

    return 0;
}
