#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> stk;
    for (char& ch : s) {
        if ('A' <= ch && ch <= 'Z') cout << ch;
        else {
            if (ch == '(') stk.push(ch);
            else if (strchr("*/", ch)) {
                while (!stk.empty() && strchr("*/", stk.top())) {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
            else {
                while (!stk.empty() && strchr("*/+-", stk.top())) {
                    cout << stk.top();
                    stk.pop();
                }
                if (strchr("+-", ch)) stk.push(ch);
                else stk.pop();
            }
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
