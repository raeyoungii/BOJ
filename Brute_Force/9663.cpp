#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, cnt = 0;
int board[15];

bool isValid(int pos) {
    for (int i = 0; i < pos; i++) {
        if (board[pos] == board[i] || abs(board[pos] - board[i]) == pos - i) {
            return false;
        }
    }
    return true;
}

void dfs(int pos) {
    if (pos == n) { cnt++; return; }
    for (int i = 0; i < n; i++) {
        board[pos] = i;
        if (isValid(pos)) {
            dfs(pos + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(0);
    cout << cnt << "\n";
    return 0;
}
