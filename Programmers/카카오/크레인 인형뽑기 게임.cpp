#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = (int) board.size();
    stack<int> vs[N + 1];
    stack<int> s;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (board[j][i]) vs[i + 1].push(board[j][i]);
        }
    }
    for (int& m : moves) {
        if (vs[m].empty()) continue;
        if (!s.empty() && vs[m].top() == s.top()) {
            s.pop();
            answer += 2;
        } else s.push(vs[m].top());
        vs[m].pop();
    }
    return answer;
}