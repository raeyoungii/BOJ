#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

bool getTrue(string s) {
    deque<char> dq;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') dq.push_back(s[i]);
        else if (!dq.empty() && ((s[i] == ')' && dq.back() == '(') || (s[i] == '}' && dq.back() == '{') ||
            (s[i] == ']' && dq.back() == '['))) dq.pop_back();
        else return false;

    }
    if (dq.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if (getTrue(s)) answer++;
        rotate(s.rbegin(), s.rbegin() + 1, s.rend());
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "(((";
    cout << solution(s);
    return 0;
}
