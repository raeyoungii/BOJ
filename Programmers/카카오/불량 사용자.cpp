#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int N;
vector<int> v[8];
bool vst[8];
set<string> st;

bool match(string& uid, string& bid) {
    if (uid.size() != bid.size()) return false;
    for (int i = 0; i < bid.size(); i++) {
        if (bid[i] == '*') continue;
        if (uid[i] != bid[i]) return false;
    }
    return true;
}

void f(int idx) {
    if (idx == N) {
        string s;
        for (int i = 0; i < 8; i++) {
            if (vst[i]) s += to_string(i);
        }
        st.insert(s);
        return;
    }
    for (int i = 0; i < v[idx].size(); i++) {
        if (vst[v[idx][i]]) continue;
        vst[v[idx][i]] = true;
        f(idx + 1);
        vst[v[idx][i]] = false;
    }
}

int solution(vector<string>& user_id, vector<string>& banned_id) {
    int answer = 0;
    N = (int) banned_id.size();
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (match(user_id[j], banned_id[i])) {
                v[i].push_back(j);
            }
        }
    }
    f(0);
    answer = (int) st.size();
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};
    cout << solution(user_id, banned_id) << nl;
    return 0;
}
