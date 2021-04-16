#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int k, cnt;
int D[11];

void dfs(int pos, vector<int>& v) {
    if (pos == 0) {
        cnt++;
        if (cnt == k) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) cout << "+";
            }
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (pos - i < 0) continue;
        v.push_back(i);
        dfs(pos - i, v);
        v.pop_back();
    }
}

// 1, 2, 3 더하기 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(D, -1, sizeof(D));
    vector<int> v;
    int n; cin >> n >> k;
    dfs(n, v);
    if (cnt < k) cout << "-1\n";
    return 0;
}
