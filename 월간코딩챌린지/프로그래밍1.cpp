#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < absolutes.size(); i++) {
        answer += absolutes[i] * (signs[i] ? 1 : -1);
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> absolutes = {4, 7, 12};
    vector<bool> signs = {true, false, true};
    cout << solution(absolutes, signs);
    return 0;
}
