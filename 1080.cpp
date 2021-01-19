#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> v1;
vector<string> v2;
int cnt = 0;

void flip(int y, int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v1[y + i][x + j] = (v1[y + i][x + j] == '0') ? '1' : '0';
        }
    }
    cnt++;
}

bool chk(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v1[i][j] != v2[i][j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v1.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v2.push_back(s);
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (v1[i][j] != v2[i][j]) flip(i, j);
        }
    }
    if (chk(n, m)) cout << cnt << "\n";
    else cout << "-1\n";
    return 0;
}
