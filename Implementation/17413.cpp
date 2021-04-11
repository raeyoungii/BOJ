#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; getline(cin, s);
    stack<char> stk;
    bool flag = false;
    for (char & ch : s) {
        if (ch == '<') {
            while (!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            cout << '<';
            flag = true;
        } else if (ch == '>') {
            cout << '>';
            flag = false;
        } else {
            if (flag) cout << ch;
            else {
                if (ch == ' ') {
                    while (!stk.empty()) {
                        cout << stk.top();
                        stk.pop();
                    }
                    cout << ' ';
                }
                else stk.push(ch);
            }
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
