#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> psum(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        sum += v[i];
        psum[i] += sum;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << psum[b] - psum[a - 1] << "\n";
    }
    return 0;
}
