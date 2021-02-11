#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> frame(101); // first: 추천수, second: 시간
    int size = 0;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (frame[k].first == 0) {
            if (size == n) {
                int num = 0, cnt = INT_MAX, time = INT_MAX;
                for (int j = 1; j <= 100; j++) {
                    if (frame[j].first == 0) continue;
                    if (frame[j].first < cnt) {
                        num = j;
                        cnt = frame[j].first;
                        time = frame[j].second;
                    } else if (cnt == frame[j].first) {
                        if (frame[j].second < time) {
                            num = j;
                            cnt = frame[j].first;
                            time = frame[j].second;
                        }
                    }
                }
                frame[num] = {0, 0};
            } else size++;
            frame[k].second = i;
        }
        frame[k].first++;
    }
    for (int i = 1; i <= 100; i++) {
        if (frame[i].first == 0) continue;
        cout << i << " ";
    }
    return 0;
}
