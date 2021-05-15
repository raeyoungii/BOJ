#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;

int adj[220][220];

int solution(int n, int s, int a, int b, vector<vector<int>>& fares) {
    int answer = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = (i == j ? 0 : INF);
        }
    }
    for (auto& v : fares) {
        adj[v[0]][v[1]] = v[2];
        adj[v[1]][v[0]] = v[2];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        answer = min(answer, adj[s][i] + adj[i][a] + adj[i][b]);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    cout << solution(6, 4, 6, 2, fares) << nl;
    return 0;
}
