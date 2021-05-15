#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

vector<string> solution(vector<string> &s) {
    vector<string> answer;
    for (string &str : s) {
        deque<char> dq;
        string tmp;
        for (char &ch : str) {
            dq.push_back(ch);
            int N = (int) dq.size();
            if (N >= 3 && (dq[N - 3] == '1' && dq[N - 2] == '1' && dq[N - 1] == '0')) {
                for (int i = 0; i < 3; i++) dq.pop_back();
                tmp += "110";
            }
        }
        int idx = -1;
        for (int i = (int) dq.size() - 1; i >= 0; i--) {
            if (dq[i] == '0') { idx = i; break; }
        }
        string res;
        for (int i = 0; i <= idx; i++) res += dq[i];
        res += tmp;
        for (int i = idx + 1; i < dq.size(); i++) res += dq[i];
        answer.push_back(res);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> s = {"1110", "100111100", "0111111010", "11011110101011", "110010"};
    vector<string> ans = solution(s);
    for (auto &str : ans) cout << str << ' ';
    return 0;
}
