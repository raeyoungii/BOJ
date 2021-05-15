#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    vector<string> vs(13);
    for (int i = 1; i <= 12; i++) {
        string chk;
        for (int j = 0; j < i; j++) chk += 'w';
        for (int j = 0; j < i; j++) chk += 'o';
        for (int j = 0; j < i; j++) chk += 'l';
        for (int j = 0; j < i; j++) chk += 'f';
        vs[i] = chk;
    }
    while (!s.empty()) {
        int cnt = 0;
        for (char& ch : s) {
            if (ch == 'w') cnt++;
            else break;
        }
        if (cnt > 0 && s.substr(0, cnt * 4) == vs[cnt]) {
            s = s.substr(cnt * 4, s.size());
        } else {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";
    return 0;
}
