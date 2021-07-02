#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int get_p1(vector<int>& answers) {
    int ret = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == i % 5 + 1) ret++;
    }
    return ret;
}

int get_p2(vector<int>& answers) {
    int ret = 0;
    int A[4] = {1, 3, 4, 5};
    for (int i = 0; i < answers.size(); i++) {
        if (!(i % 2) && answers[i] == 2) ret++;
        else if (i % 2 && answers[i] == A[(i / 2) % 4]) ret++;
    }
    return ret;
}

int get_p3(vector<int>& answers) {
    int ret = 0;
    int A[5] = {3, 1, 2, 4, 5};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == A[(i / 2) % 5]) ret++;
    }
    return ret;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p = {get_p1(answers), get_p2(answers), get_p3(answers)};
    int mx = *max_element(p.begin(), p.end());
    for (int i = 0; i < 3; i++) {
        if (p[i] == mx) answer.push_back(i + 1);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> answers = {1,2,3,4,5};
    vector<int> v = solution(answers);
    for (auto& x : v) cout << x << ' ';
    return 0;
}
