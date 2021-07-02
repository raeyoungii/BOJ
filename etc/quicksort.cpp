#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int partition(int left, int right, vector<int>& arr) {
    int mid = (left + right) / 2;
    swap(arr[left], arr[mid]);
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (pivot < arr[j]) j--;
        while (i < j && pivot >= arr[i]) i++;
        swap(arr[i], arr[j]);
    }
    arr[left] = arr[i];
    arr[i] = pivot;
    return i;
}

void quickSort(int left, int right, vector<int>& arr) {
    if (left >= right) return;
    int pi = partition(left, right, arr);
    quickSort(left, pi - 1, arr);
    quickSort(pi + 1, right, arr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {7, 9, 5, 4, 8, 2, 1, 6, 3};
    quickSort(0, (int) arr.size() - 1, arr);
    for (int x : arr) cout << x << ' ';
    return 0;
}
