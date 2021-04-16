#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a = 1;
    vector<int> v;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            v.push_back(a + j);
            v.push_back(a);
        }
        v.push_back(a + i - 1);
        a++;
    }
    v.push_back(1);
    cout << v.size() << nl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
