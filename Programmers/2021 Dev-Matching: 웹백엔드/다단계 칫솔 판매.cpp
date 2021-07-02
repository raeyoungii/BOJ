#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

void dfs(string& child, int k, map<string, string>& mp_r, map<string, int>& mp_a) {
    string parent = mp_r[child];
    if (parent.empty() || k == 0) return;
    mp_a[child] += k - k / 10;
    dfs(parent, k / 10, mp_r, mp_a);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> mp_r;
    map<string, int> mp_a;
    for (int i = 0; i < enroll.size(); i++) mp_r[enroll[i]] = referral[i];
    for (int i = 0; i < seller.size(); i++) dfs(seller[i], amount[i] * 100, mp_r, mp_a);
    for (auto & s : enroll) answer.push_back(mp_a[s]);
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};
    vector<int> v = solution(enroll, referral, seller, amount);
    for (int& x : v) cout << x << ' ';
    return 0;
}
