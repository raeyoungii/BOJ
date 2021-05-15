#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mp;

    string tmp;
    for (char& ch : s) {
        if (strchr("{}", ch)) continue;
        if (ch != ',') tmp += ch;
        else {
            mp[stoi(tmp)]++;
            tmp = "";
        }
    }
    mp[stoi(tmp)]++;
    vector<pair<int, int>> vp(mp.begin(), mp.end());
    sort(vp.begin(), vp.end(), compare);
    for (auto& p : vp) answer.push_back(p.first);
    return answer;
}