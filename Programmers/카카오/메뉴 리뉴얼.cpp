#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int& c : course) {
        map<string, int> mp;
        for (string& o : orders) {
            if (o.size() < c) continue;
            sort(o.begin(), o.end());
            vector<int> chk(o.size());
            for (int i = c; i < o.size(); i++) chk[i] = 1;
            do {
                string s;
                for (int i = 0; i < o.size(); i++) {
                    if (!chk[i]) s += o[i];
                }
                mp[s]++;
            } while (next_permutation(chk.begin(), chk.end()));
        }
        int mx = 0;
        for (auto& it : mp) mx = max(mx, it.second);
        if (mx == 1) continue;
        for (auto& it : mp) {
            if (it.second == mx) answer.push_back(it.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}