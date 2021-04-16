#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool vst[4];
deque<int> gear[4];

void Rotate(int n, int d) {
    if (d == 1) {
        int tmp = gear[n].back();
        gear[n].pop_back();
        gear[n].push_front(tmp);
    }
    else if (d == -1) {
        int tmp = gear[n].front();
        gear[n].pop_front();
        gear[n].push_back(tmp);
    }
}

void SetRotation(int n, int d) {
    vst[n] = true;
    if (n - 1 >= 0 && !vst[n - 1]) {
        if (gear[n - 1][2] != gear[n][6])
            SetRotation(n - 1, -1 * d);
    }
    if (n + 1 < 4 && !vst[n + 1]){
        if (gear[n + 1][6] != gear[n][2])
            SetRotation(n + 1, -1 * d);
    }
    Rotate(n, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 0: N극, 1: S극
    for (auto & g : gear) {
        for (int i = 0; i < 8; i++) {
            char c; cin >> c;
            g.push_back(c - '0');
        }
    }
    int k; cin >> k;
    while (k--) {
        int n, d; cin >> n >> d;
        memset(vst, false, sizeof(vst));
        SetRotation(n - 1, d);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == 1) {
            ans += pow(2, i);
        }
    }
    cout << ans << "\n";
    return 0;
}
