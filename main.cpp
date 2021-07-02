#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

vector<string> solution(vector<string> versions) {
    vector<string> answer;
    vector<vector<int>> vv;
    for (auto& s : versions) {
        istringstream ss(s);
        string stringBuffer;
        vector<int> v;
        while (getline(ss, stringBuffer, '.')) {
            v.push_back(stoi(stringBuffer));
        }
        vv.push_back(v);
    }
    sort(vv.begin(), vv.end());
    for (auto& v : vv) {
        string s;
        for (int i = 0; i < v.size(); i++) {
            s += to_string(v[i]);
            if (i != v.size() - 1) s += ".";
        }
        answer.push_back(s);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> versions = {"2.2.0", "2.0.4", "1.3", "2.1", "3", "1", "1.12.1"};
    vector<string> answer = solution(versions);
    for (auto& x : answer) cout << x << nl;
    return 0;
}
