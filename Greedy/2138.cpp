#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 100001;

int n;
vector<int> a;
vector<int> b;
vector<int> arr;
int cnt = 0;
int cnt1 = MAX;
int cnt2 = MAX;

void flip(int x) {
    for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < n)
            arr[i] = 1 - arr[i];
    }
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string s1; string s2; cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        a.push_back(s1[i] - '0');
        b.push_back(s2[i] - '0');
    }
    if (a == b) cout << "0\n";
    else {
        arr = a;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] != b[i - 1]) flip(i);
        }
        if (arr == b) cnt1 = cnt;

        cnt = 0;
        arr = a;
        flip(0);
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] != b[i - 1]) flip(i);
        }
        if (arr == b) cnt2 = cnt;

        if (cnt1 == MAX && cnt2 == MAX) cout << "-1\n";
        else cout << min(cnt1, cnt2) << "\n";
    }
    return 0;
}
