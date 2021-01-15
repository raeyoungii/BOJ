#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define n 9
#define k 7

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr(n);
    vector<int> chk(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++) chk[i] = 0;
    for (int i = k; i < n; i++) chk[i] = 1;
    do {
        vector<int> arr2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (chk[i] == 1) continue;
            arr2.push_back(arr[i]);
        }
        for (int i = 0; i < k; i++) sum += arr2[i];
        if (sum == 100) {
            for (int i = 0; i < k; i++) {
                cout << arr2[i] << "\n";
            }
            return 0;
        }
    } while (next_permutation(chk.begin(), chk.end()));
    return 0;
}
