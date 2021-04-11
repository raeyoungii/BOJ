#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solution(string name) {
    int answer = 0;
    int N = name.size();
    int mn = N - 1;
    for (int i = 0; i < N; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        int next = i + 1;
        while (next < N && name[next] == 'A') next++;
        // 최소 이동거리 (연속된 A를 사이에 두고 뒤로 가야할지 앞으로 가야할지 계산)
        mn = min(mn, i + i + N - next);
    }
    answer += mn;
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string name = "JEROEN";
    cout << solution(name) << "\n";
    return 0;
}
