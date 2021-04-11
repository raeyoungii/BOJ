#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string solution(string number, int k) {
    string answer = "";
    int N = number.size();
    deque<char> dq;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.back() < number[i] && cnt < k) {
            dq.pop_back();
            cnt++;
        }
        dq.push_back(number[i]);
    }
    for (int i = 0; i < dq.size() - (k - cnt); i++) {
        answer += dq[i];
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string number = "1231234";
    int k = 3;
    cout << solution(number, k) << "\n";
    return 0;
}
