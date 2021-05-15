#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

bool check(string& u) {
    stack<char> s;
    for (char& ch : u) {
        if (ch == '(') s.push(ch);
        else if (!s.empty()) s.pop();
        else return false;
    }
    if (!s.empty()) return false;
    return true;
}

string f(string& p) {
    if (p.empty()) return p;
    int tmp = 0, idx = 0;
    for (char& ch : p) {
        if (ch == '(') tmp++;
        else tmp--;
        idx++;
        if (!tmp) break;
    }
    string u = p.substr(0, idx);
    string v = p.substr(idx, p.size());
    if (check(u)) {
        return u + f(v);
    }
    u.erase(u.begin());
    u.pop_back();
    for (char& ch : u) {
        if (ch == '(') ch = ')';
        else ch = '(';
    }
    return "(" + f(v) + ")" + u;
}

string solution(string p) {
    string answer = f(p);
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string p = ")(";
    cout << solution(p) << nl;
    return 0;
}
