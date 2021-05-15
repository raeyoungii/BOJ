#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll func(ll a, ll b, char c) {
    if (c == '*') return a * b;
    else if (c == '+') return a + b;
    else return a - b;
}

ll solution(string expression) {
    ll answer = 0;
    string op = "*+-";
    vector<ll> N;
    vector<char> O;
    string tmp;
    for (char& ch : expression) {
        if (strchr("*+-", ch)) {
            O.push_back(ch);
            N.push_back(stoi(tmp));
            tmp = "";
        }
        else tmp += ch;
    }
    N.push_back(stoi(tmp));
    do {
        vector<ll> tmpN(N.begin(), N.end());
        vector<char> tmpO(O.begin(), O.end());
        for (char& o : op) {
            for (int i = 0; i < tmpO.size(); i++) {
                if (tmpO[i] == o) {
                    tmpN[i] = func(tmpN[i], tmpN[i + 1], tmpO[i]);
                    tmpN.erase(tmpN.begin() + i + 1);
                    tmpO.erase(tmpO.begin() + i);
                    i--;
                }
            }
        }
        answer = max(answer, abs(tmpN[0]));
    } while (next_permutation(op.begin(), op.end()));
    return answer;
}