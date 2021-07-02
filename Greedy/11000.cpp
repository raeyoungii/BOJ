#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i = 0; i < N; i++) {
        int S, T; cin >> S >> T;
        pq.emplace(S, T);
    }
    priority_queue<int, vector<int>, greater<>> end_points;
    while (!pq.empty()) {
        pair<int, int> l = pq.top();
        pq.pop();
        if (!end_points.empty()) {
            if (l.first >= end_points.top()) {
                end_points.pop();
            }
        }
        end_points.push(l.second);
    }
    cout << end_points.size() << nl;
    return 0;
}
