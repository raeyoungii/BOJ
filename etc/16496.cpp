#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

bool compare(const string &a, const string &b) {
    string s1 = a + b;
    string s2 = b + a;
    return s1 > s2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<string> v(N);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end(), compare);
    string ret;
    for (auto &x : v) ret += x;
    if (ret[0] == '0') cout << '0';
    else cout << ret;
    return 0;
}
