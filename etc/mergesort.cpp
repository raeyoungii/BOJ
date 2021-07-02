#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

void merge(int left, int mid, int right, vector<int>& arr) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    int ll = (int) L.size(), rl = (int) R.size();
    while (i < ll && j < rl) {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }
    while (i < ll) arr[k++] = L[i++];
    while (j < rl) arr[k++] = R[j++];
}

void mergeSort(int left, int right, vector<int>& arr) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        merge(left, mid, right, arr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {7, 9, 5, 4, 8, 2, 1, 6, 3};
    mergeSort(0, (int) arr.size() - 1, arr);
    for (int x : arr) cout << x << ' ';
    return 0;
}
