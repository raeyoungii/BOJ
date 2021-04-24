#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

ll answer;
vector<int> adj[303030];

void f(int u, int k, vector<ll>& A) {
    for (int v : adj[u]) {
        if (v == k) continue;
        if (adj[v].size() != 1) f(v, u, A);
        answer += abs(A[v]);
        A[u] += A[v];
        A[v] = 0;
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<ll> A(a.begin(), a.end());
    ll sum = 0;
    bool ok = true;
    for (ll x : A) {
        sum += x;
        if (x) ok = false;
    }
    if (ok) return 0;
    if (sum) return -1;
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    f(0, -1, A);
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
