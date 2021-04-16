#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

long long answer;

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = (int) a.size();
    // 안되는거 미리 확인
    if (all_of(a.begin(), a.end(), [](int i){ return i == 0; })) return 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum) return -1;

    vector<vector<int>> b(n);
    for (int i = 0; i < edges.size(); i++) {
        b[edges[i][0]].push_back(edges[i][1]);
        b[edges[i][1]].push_back(edges[i][0]);
    }
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        dq.emplace_back(b[i].size(), i);
    }
    sort(dq.begin(), dq.end());
    vector<bool> vst(n, false);
    for (int i = 0; i < n; i++) {
        vst[dq[0].second] = true;
        for (int j = 0; j < b[dq[0].second].size(); j++) {
            for (int k = 0; k < n; k++) {
                if (dq[k].second == b[dq[0].second][j]) dq[k].first--;
            }
            if (vst[b[dq[0].second][j]]) continue;
            answer += (long long) abs(a[dq[0].second]);
            a[b[dq[0].second][j]] += a[dq[0].second];
            a[dq[0].second] = 0;
        }
        dq.pop_front();
        sort(dq.begin(), dq.end());
    }

    // 마지막 확인
    if (!all_of(a.begin(), a.end(), [](int i){ return i == 0; })) return -1;
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {-5 ,0, 1, 2, 2};
    vector<vector<int>> edges = {{0, 1}, {2, 4}, {2, 3}, {0, 2}};
    cout << solution(a, edges);
    return 0;
}

//vector<int> a = {-5 ,0, 2, 1, 2};
//vector<vector<int>> edges = {{0, 1}, {3, 4}, {2, 3}, {0, 3}};
//vector<int> a = {0, 1, 0};
//vector<vector<int>> edges = {{0, 1}, {1, 2}};
//vector<int> a = {5, 5, -5, 0, 0, 5, 0, -5, -5};
//vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}};
