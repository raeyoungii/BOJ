#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int INF = 987654321;

int solution(string& s) {
    int answer = INF;
    if (s.size() == 1) return 1;
    int N = (int) s.size();
    for (int i = 1; i <= N / 2; i++) {
        vector<string> v;
        int k = 0;
        while(k + i < N) {
            v.push_back(s.substr(k, i));
            k += i;
        }
        if (k != N) v.push_back(s.substr(k, N));
        string ret, tmp = v[0];
        int cnt = 1;
        for (int j = 1; j < v.size(); j++) {
            if (tmp == v[j]) cnt++;
            else {
                if (cnt > 1) ret += to_string(cnt) + tmp;
                else ret += tmp;
                tmp = v[j];
                cnt = 1;
            }
        }
        if (cnt > 1) ret += to_string(cnt) + tmp;
        else ret += tmp;
        answer = min(answer, (int) ret.size());
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "a";
    cout << solution(s) << nl;
    return 0;
}
