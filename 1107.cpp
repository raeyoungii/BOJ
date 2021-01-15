#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int min_cnt;
bool btn[10] = {false,};

void dfs(const string& s) {
    if (s.length() >= 6) return;
    for (int i = 0; i < 10; i++) {
        if (btn[i]) continue;
        string tmp = s + to_string(i);
        min_cnt = min(min_cnt, abs(n - stoi(tmp)) + (int) tmp.length());
        dfs(tmp);

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int m; cin >> m;
    min_cnt = abs(n - 100);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        btn[k] = true;
    }
    if (m < 10) dfs("");
    cout << min_cnt << "\n";
    return 0;
}
