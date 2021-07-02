#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

bool getTrue(string& s) {
    stack<char> stk;
    for (char& ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
        else if (!stk.empty() && ((ch == ')' && stk.top() == '(') || (ch == '}' && stk.top() == '{') ||
            (ch == ']' && stk.top() == '['))) stk.pop();
        else return false;
    }
    if (!stk.empty()) return false;
    return true;
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
