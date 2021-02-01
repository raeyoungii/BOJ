#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, k, c; cin >> n >> d >> k >> c;
    vector<int> v(n);
    vector<int> vst(d + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    int cnt = 0;
    // 윈도우 생성
    for (int i = 0; i < k; i++) {
        if (vst[v[i]] == 0) cnt++;
        vst[v[i]]++;
    }
    int max_cnt = cnt;
    for (int i = 1; i < n; i++) {
        // 최댓값 갱신
        if (max_cnt <= cnt) {
            max_cnt = (vst[c] == 0 ? cnt + 1 : cnt); // 쿠폰 확인
        }
        // 윈도우 -1
        vst[v[i - 1]]--;
        if (vst[v[i - 1]] == 0) cnt--;
        // 윈도우 +1
        if (vst[v[(i + k - 1) % n]] == 0) cnt++;
        vst[v[(i + k - 1) % n]]++;
    }
    cout << max_cnt << "\n";
    return 0;
}
// 슬라이딩 윈도우