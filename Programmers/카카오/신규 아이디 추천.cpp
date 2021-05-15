#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

string solution(string& new_id) {
    string answer;
    for (char& ch : new_id) ch = tolower(ch);
    string ret;
    for (char& ch : new_id) {
        if (isalpha(ch) || isdigit(ch) || strchr("-_.", ch)) ret += ch;
    }
    new_id = ret;
    ret.clear();
    for (char& ch : new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }
    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();
    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "123_.def";
    string ans = solution(s);
    cout << ans << nl;
    return 0;
}

