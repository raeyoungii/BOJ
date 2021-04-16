#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;
deque<pair<bool, int>> a;

// 벨트가 한 칸 회전한다.
void rotate() {
    a[n - 1].first = false;
    a.push_front(a.back());
    a.pop_back();
}

// 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
// 만약 이동할 수 없다면 가만히 있는다.
void move() {
    a[n - 1].first = false;
    for (int i = n - 2; i > 0; i--) {
        if (a[i].first) {
            if (!a[i + 1].first && a[i + 1].second > 0) {
                a[i].first = false;
                a[i + 1].first = true;
                a[i + 1].second--;
            }
        }
    }
}

// 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
void put() {
    if (a[0].second > 0) {
        a[0].first = true;
        a[0].second--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        int t; cin >> t;
        a.emplace_back(false, t);
    }
    int cnt = 0, step = 0;
    while (cnt < k) {
        step++;
        cnt = 0;
        rotate();
        move();
        put();
        for (int i = 0; i < 2 * n; i++) {
            if (a[i].second == 0) cnt++;
        }
    }
    cout << step << "\n";
    return 0;
}
