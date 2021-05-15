#include <bits/stdc++.h>

using namespace std;

vector<int> db[3][2][2][2];

vector<int> getInfo(string s) {
    vector<int> ret;
    vector<string> v;
    istringstream ss(s);
    string stringBuffer;
    while (getline(ss, stringBuffer, ' ')) v.push_back(stringBuffer);
    for (int i = 0; i < 4; i++) {
        int n = 0;
        if (v[i] == "java" || v[i] == "frontend" || v[i] == "senior" ||
            v[i] == "pizza") n = 1;
        else if (v[i] == "python") n = 2;
        ret.push_back(n);
    }
    ret.push_back(stoi(v[4]));
    return ret;
}

vector<string> getQuery(string s) {
    vector<string> ret;
    istringstream ss(s);
    string stringBuffer;
    while (getline(ss, stringBuffer, ' ')) {
        if (stringBuffer == "and") continue;
        ret.push_back(stringBuffer);
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (string& i : info) {
        vector<int> I = getInfo(i);
        db[I[0]][I[1]][I[2]][I[3]].push_back(I[4]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end());
                }
            }
        }
    }
    for (string& q : query) {
        vector<string> Q = getQuery(q);
        int i1, i2, j1, j2, k1, k2, l1, l2;

        if (Q[0] == "cpp") i1 = i2 = 0;
        else if (Q[0] == "java") i1 = i2 = 1;
        else if (Q[0] == "python") i1 = i2 = 2;
        else i1 = 0, i2 = 2;

        if (Q[1] == "backend") j1 = j2 = 0;
        else if (Q[1] == "frontend") j1 = j2 = 1;
        else j1 = 0, j2 = 1;

        if (Q[2] == "junior") k1 = k2 = 0;
        else if (Q[2] == "senior") k1 = k2 = 1;
        else k1 = 0, k2 = 1;

        if (Q[3] == "chicken") l1 = l2 = 0;
        else if (Q[3] == "pizza") l1 = l2 = 1;
        else l1 = 0, l2 = 1;

        int sc = stoi(Q[4]), ans = 0;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                for (int k = k1; k <= k2; k++) {
                    for (int l = l1; l <= l2; l++) {
                        int N = db[i][j][k][l].size();
                        if (!N) continue;
                        auto it = lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), sc);
                        if (it == db[i][j][k][l].end()) continue;
                        ans += db[i][j][k][l].end() - it;
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}