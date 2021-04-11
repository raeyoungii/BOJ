#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int bit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> m;
    while(m--) {
        string cmd; cin >> cmd;
        int n;
        if (cmd == "add") { cin >> n; bit |= 1 << n; }
        else if (cmd == "remove") { cin >> n; bit &= ~(1 << n); }
        else if (cmd == "check") { cin >> n; cout << (bit & (1 << n) ? 1 : 0) << "\n"; }
        else if (cmd == "toggle") { cin >> n; bit ^= 1 << n; }
        else if (cmd == "all") bit = (1 << 21) - 1;
        else if (cmd == "empty") bit = 0;
    }
    return 0;
}
