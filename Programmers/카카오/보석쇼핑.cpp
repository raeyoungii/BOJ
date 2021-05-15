#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> mp;
    for (string& g : gems) mp[g] = 0;
    int N = (int) gems.size(), M = (int) mp.size();
    int l = 0, r = 0;
    int curSize = 1;
    int mn = 123456;
    int ansL, ansR;
    mp[gems[r]]++;
    while (l < N && r < N) {
        if (curSize == M) {
            if (r - l + 1 < mn) {
                mn = r - l + 1;
                ansL = l + 1;
                ansR = r + 1;
            }
            mp[gems[l]]--;
            if (mp[gems[l]] == 0) curSize--;
            l++;
        } else {
            r++;
            if (r == N) break;
            mp[gems[r]]++;
            if (mp[gems[r]] == 1) curSize++;
        }
    }
    answer = {ansL, ansR};
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    vector<int> ans = solution(gems);
    cout << ans[0] << ' ' << ans[1] << nl;
    return 0;
}
