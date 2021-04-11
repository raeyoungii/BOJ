#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[1000001];
bool vst[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    queue<int> q;
    q.push(S);
    vst[S] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == G) {
            cout << cnt[now] << "\n";
            return 0;
        }
        if (now + U <= F && !vst[now + U]) {
            q.push(now + U);
            cnt[now + U] = cnt[now] + 1;
            vst[now + U] = true;
        }
        if (now - D >= 1 && !vst[now - D]) {
            q.push(now - D);
            cnt[now - D] = cnt[now] + 1;
            vst[now - D] = true;
        }
    }
    cout << "use the stairs\n";
    return 0;
}
