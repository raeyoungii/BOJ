#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    deque<int> dq;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.back() < s[i] - '0' && cnt < k) {
            dq.pop_back();
            cnt++;
        }
        dq.push_back(s[i] - '0');
    }
    for (int i = 0; i < dq.size() - (k - cnt); i++) {
        cout << dq[i];
    }
    return 0;
}
