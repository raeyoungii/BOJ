#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& stones, int k, int mid) {
    int cnt = 0;
    for (int& stone : stones) {
        if (stone < mid) {
            cnt++;
            if (cnt >= k) return false;
        } else cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int l = 1, r = *max_element(stones.begin(), stones.end());
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(stones, k, mid)) l = mid + 1;
        else r = mid - 1;
    }
    answer = r;
    return answer;
}